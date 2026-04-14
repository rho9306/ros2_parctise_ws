import rclpy
from rclpy.node import Node
from chapt4_interfaces.srv import FaceDetector
import face_recognition
import cv2
from ament_index_python.packages import get_package_share_directory
import os
from cv_bridge import CvBridge
import time 

class FaceDetectNode(Node):
    def __init__(self):
        super().__init__('face_detect_node')
        self.bridge = CvBridge()
        self.service = self.create_service(FaceDetector, 
        'face_detect', self.detect_face_callback)
        self.number_of_times_to_upsample=1
        self.model='hog'
        self.default_image_path = get_package_share_directory(
        'demo_python_service'
         )+'/resource/default.jpg'

    def detect_face_callback(self, request, response):
        if request.image.data:
            cv_image = self.bridge.imgmsg_to_cv2(request.image)
        else:
            cv_image = cv2.imread(self.default_image_path)
        start_time = time.time()
        self.get_logger().info("already download")
        face_location = face_recognition.face_locations(
        cv_image, number_of_times_to_upsample=self.number_of_times_to_upsample
        , model=self.model)
        response.use_time = time.time() - start_time
        response.number = len(face_location)
        for top, right, left, bottom, in face_location:
            response.top.append(top)
            response.right.append(right)
            response.left.append(left)
            response.bottom.append(bottom)

        return response
def main():
    rclpy.init()
    node = FaceDetectNode()
    rclpy.spin(node)
    rclpy.shutdown()
