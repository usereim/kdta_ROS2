#include "simple_pkg_cpp/subscriber.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = make_shared<HelloSubscriber>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

