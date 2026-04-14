import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue

class NovelPubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f'{node_name} start')
        self.create_timer(5, self.timer_callback)
        self.novels_queue = Queue()
        self.novel_publisher_ = self.create_publisher(String, 'novel', 10)

    def download(self, url):
        response = requests.get(url)
        response.encoding = 'utf-8'
        text = response.text
        self.get_logger().info(f'download{url}...,{len(text)}')
        for line in text.splitlines():
            self.novels_queue.put(line)

    def timer_callback(self):
        if self.novels_queue.qsize()>0:
            line = self.novels_queue.get()
            msg = String()
            msg.data = line
            self.novel_publisher_.publish(msg)
            self.get_logger().info(f'pub {msg}')
    
def main():
    rclpy.init()
    node = NovelPubNode('novel_pub')
    node .download('')
    rclpy.spin(node)
    rclpy.shutdown