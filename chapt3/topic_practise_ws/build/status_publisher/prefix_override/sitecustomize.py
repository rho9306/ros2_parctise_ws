import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/rho9/chapt3/topic_practise_ws/install/status_publisher'
