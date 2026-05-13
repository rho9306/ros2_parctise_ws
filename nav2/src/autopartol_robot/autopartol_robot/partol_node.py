from geometry_msgs.msg import PoseStamped, Pose
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from rclpy.node import Node
from tf2_ros import TransformListener, Buffer
from tf_transformations import euler_from_quaternion, quaternion_from_euler
import math
from autopartol_interfaces.srv import SpeechText
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class PartolNode(BasicNavigator):
    def __init__(self, node_name="partol_node"):
        super().__init__(node_name)
        self.declare_parameter("initial_point", [0.0, 0.0, 0.0])
        self.declare_parameter("target_points", [0.0, 0.0, 0.0, 1.0, 1.0, 1.57])
        self.declare_parameter('img_save_path','')
        self.initial_point_ = self.get_parameter("initial_point").value
        self.target_points = self.get_parameter("target_points").value
        self.img_save_path = self.get_parameter("img_save_path").value
        self.buffer = Buffer()
        self.listener = TransformListener(self.buffer, self)
        self.speech_client_ = self.create_client(SpeechText,'speech_text')
        self.cv_bridge_ = CvBridge()
        self.latest_img_ = None
        self.img_sub_ = self.create_subscription(Image,'/camera_sensor/image_raw',self.img_callback,1)

    def img_callback(self,msg):
        self.latest_img_ = msg

    def record_img(self):
        if self.latest_img_ is not None:
            pose = self.get_current_pose()
            cv_image = self.cv_bridge_.imgmsg_to_cv2(self.latest_img_)
            cv2.imwrite(
                f'{self.img_save_path}img_{pose.translation.x:3.2f}_{pose.translation.y:3.2f}.png',
                cv_image
            )

    def get_pose_by_xyyaw(self, x, y, yaw):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = x
        pose.pose.position.y = y
        quat = quaternion_from_euler(0, 0, yaw)
        pose.pose.orientation.x = quat[0]
        pose.pose.orientation.y = quat[1]
        pose.pose.orientation.z = quat[2]
        pose.pose.orientation.w = quat[3]
        return pose

    def init_robot_pose(self):
        init_pose = self.get_pose_by_xyyaw(
            self.initial_point_[0], 
            self.initial_point_[1], 
            self.initial_point_[2]
        )
        self.setInitialPose(init_pose)
        self.waitUntilNav2Active()

    def get_target_points(self):
        points = []
        target_points = self.get_parameter("target_points").value
        if target_points is None:
            self.get_logger().warn("target_points parameter is None")
            return points
        
        for index in range(int(len(target_points) / 3)):
            x = target_points[index * 3]
            y = target_points[index * 3 + 1]
            yaw = target_points[index * 3 + 2]
            points.append([x, y, yaw])
        return points

    def nav_to_pose(self, target_point):
        self.goToPose(target_point)
        while not self.isTaskComplete():
            feedback = self.getFeedback()
            if feedback:
                self.get_logger().info(f"Distance remaining: {feedback.distance_remaining}")
        result = self.getResult()
        self.get_logger().info(f"Navigation result: {result}")

    def get_current_pose(self):
        while rclpy.ok():
            try:
                tf = self.buffer.lookup_transform(
                    "map", "base_footprint", rclpy.time.Time(), rclpy.duration.Duration(seconds=1))
                return tf.transform
            except Exception as e:
                self.get_logger().warn(f"Transform lookup failed: {str(e)}")

    def speech_text(self, text):
        # 调用服务合成语音
        while not self.speech_client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('语音合成服务未上线，等待中...')

        request = SpeechText.Request()
        request.text = text
        future = self.speech_client_.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            response = future.result()
            if response.result == True:
                self.get_logger().info(f'语音合成成功{text}')
            else:
                self.get_logger().warn(f'语音合成失败{text}')
        else:
            self.get_logger().warn(f'语音合成服务响应失败')
                



def main():
    rclpy.init()
    partol = PartolNode()
    partol.speech_text('正在准备初始化位置')
    partol.init_robot_pose()
    partol.speech_text('初始化位置完成')

    while rclpy.ok():
        points = partol.get_target_points()
        if not points:
            partol.get_logger().warn("No target points available")
            break
            
        for point in points:
            if not rclpy.ok():
                break
            x, y, yaw = point[0], point[1], point[2]
            target_pose = partol.get_pose_by_xyyaw(x, y, yaw)
            partol.speech_text(f'正在准备前往{x},{y}目标点')
            partol.nav_to_pose(target_pose)
            partol.speech_text(f'已经到达{x},{y},正在准备记录图像')
            partol.record_img()
            partol.speech_text(f'图像记录完成')
        
        break

    rclpy.shutdown()


if __name__ == "__main__":
    main()
