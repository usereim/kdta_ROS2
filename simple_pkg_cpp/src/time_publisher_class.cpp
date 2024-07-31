#include <iostream>
#include <chrono>
#include "simple_pkg_cpp/time_pub.hpp"
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main()
{
    rclcpp::init(0, nullptr);
    auto node = std::make_shared<TimePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

