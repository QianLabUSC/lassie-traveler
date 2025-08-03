import rclpy
from rclpy.node import Node
import time

from traveler_msgs.msg import TravelerConfig, TravelerMode

class GeneralTrajTest(Node):
    def __init__(self):
        super().__init__('GeneralTrajTest')

        # Publishers for both message types
        self.config_publisher = self.create_publisher(TravelerConfig, '/traveler/config', 10)
        self.mode_publisher = self.create_publisher(TravelerMode, '/traveler/start_flag', 10)

    def handle_params(self, msg):
        self.config_publisher.publish(msg)

    def handle_start(self, msg):
        self.mode_publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = GeneralTrajTest()
    traveler_mode_ = 8
    # data_ = [1.0, 1.0, 0.0, 4.0, 20.0]
    data_ = [0.0, -0.18, 0.01, 0.0, -0.2, 0.01, 0.0, -0.22, 0.01, 0.05, -0.22, 0.01]
    # data_ = [0.0, -0.18, 0.01, 0.0, -0.25, 0.01, 0.0, -0.2, 0.01]
    traveler_config = TravelerConfig(
        traveler_mode = traveler_mode_,  # Example mode
        data = data_  # Example data
    )
    for i in range(3):
        node.handle_params(traveler_config)
        time.sleep(0.1)
    time.sleep(3.0)
    node.handle_start(TravelerMode(
        start_flag = True,
        traveler_mode = traveler_mode_  # Example mode
    ))
    time.sleep(20.0)
    node.handle_start(TravelerMode(
        start_flag = False,
        traveler_mode = traveler_mode_  # Example mode
    ))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
