#include "simple_pkg_cpp/time_pub.hpp"

TimePublisher::TimePublisher()
: Node("hello_world"), i_(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        pub_ = this->create_publisher<std_msgs::msg::Header>("time_topic", qos_profile);
        timer_ = this->create_wall_timer(1s, std::bind(&TimePublisher::publish_time_msg,
        this));
        clock_ = rclcpp::Clock(RCL_ROS_TIME);
    }

void TimePublisher::publish_time_msg()
{
    auto msg = std_msgs::msg::Header();
    msg.frame_id = "time" + to_string(i_);
    msg.stamp = clock_.now();
    pub_->publish(msg);
    ++i_;
}