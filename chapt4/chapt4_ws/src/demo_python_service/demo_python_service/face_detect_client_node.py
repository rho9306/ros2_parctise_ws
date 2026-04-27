import rclpy
from rclpy.node import Node
from chapt4_interfaces.srv import FaceDetector
import face_recognition
import cv2
from ament_index_python.packages import get_package_share_directory
import os
from cv_bridge import CvBridge
import time 
from rcl_interfaces.srv import SetParameters
from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType

class FaceDetectClientNode(Node):
    def __init__(self):
        super().__init__('face_detect_node')
        self.bridge = CvBridge()
        self.default_image_path = get_package_share_directory(
        'demo_python_service'
         )+'/resource/default.jpg'
        self.client = self.create_client(FaceDetector
        , 'face_detect')
        self.image = cv2.imread(self.default_image_path)

    def call_set_parameters(self, parameters):
        update_param_client = self.create_client(SetParameters, '/face_detect_node/set_parameters')
        while update_param_client.wait_for_service(timeout_sec=1.0) is False:
            self.get_logger().info('waitng for the client online')
        request = SetParameters.Request()
        request.parameters = parameters
        future = update_param_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        return response
    
    def update_detect_model(self, model='hog'):
        param = Parameter()
        param.name = 'model'
        param_value = ParameterValue()
        param_value.string_value = model
        param_value.type = ParameterType.PARAMETER_STRING
        response = self.call_set_parameters([param])
        for result in response.results:
            self.get_logger().info(f"the reuslt of setting parameters:{result.successful} {result.reason}")
        

    def send_request(self):
        while self.client.wait_for_service(timeout_sec=1.0) is False:
            self.get_logger().info('waitng for the client online')
        request = FaceDetector.Request()
        request.image = self.bridge.cv2_to_imgmsg(self.image)
        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        self.get_logger().info(f"接受到响应,共有{response.number}张人脸")
  
    def show_resopnse(self, response):
        for i in range(response.number):
            top = response.top[i]
            right = response.right[i]
            bottom = response.bottom[i]
            left = response.left[i]
            cv2.rectangle(self.image, (left, top), (right,bottom), (255,0,0),2)
        cv2.imshow('Face Detection Result',self.image)
        cv2.waitKey(0)

def main():
    rclpy.init()
    node = FaceDetectClientNode()
    node.update_detect_model('hog')
    node.send_request()
    rclpy.spin(node)
    rclpy.shutdown()