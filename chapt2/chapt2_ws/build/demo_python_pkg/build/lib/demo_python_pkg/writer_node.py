from demo_python_pkg.person_node import PersonNode

class WriterNode(PersonNode):
    def __init__ (self, name:str, age:str, book:str) -> None:
        super().__init__(name,age)
        print('WriterNode __init__方法被调用了')
        self.book = book

def main():
    node = WriterNode('张三',18,'论快速入狱')
    node.eat('鱼香肉丝')