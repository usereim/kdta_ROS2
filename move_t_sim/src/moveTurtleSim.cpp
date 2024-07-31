#include "movetSim/moveTurtle.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = make_shared<MoveTurtleSim>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

