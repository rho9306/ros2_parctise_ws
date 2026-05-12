import rclpy
from rclpy.node import Node
from autopartol_interfaces.srv import SpeechText
import pyttsx3

class Speaker(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.speech_service_ = self.create_service(SpeechText, 'speech_text',
                                                      self.speech_text_callback)
        self.engine = pyttsx3.init()
        self.engine.setProperty('voice', 'zh')  # 尝试设置中文语音

    def speech_text_callback(self, request, response):
        self.get_logger().info(f'正在准备朗读: {request.text}')
        try:
            self.engine.say(request.text)
            self.engine.runAndWait()
            response.result = True
        except Exception as e:
            self.get_logger().error(f'朗读失败: {str(e)}')
            response.result = False
        return response

def main():
    rclpy.init()
    node = Speaker('speaker')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
