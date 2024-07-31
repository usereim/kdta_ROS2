#include "simple_pkg_cpp/subscriber.hpp"

HelloSubscriber::HelloSubscriber()
: Node("hello_world")
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        sub_ = this->create_subscription<std_msgs::msg::String>("helloworld", qos_profile,
        std::bind(&HelloSubscriber::sub_helloworld_msg, this, std::placeholders::_1));
    }

void HelloSubscriber::sub_helloworld_msg(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(get_logger(), "i heard : '%s'", msg->data.c_str());
}