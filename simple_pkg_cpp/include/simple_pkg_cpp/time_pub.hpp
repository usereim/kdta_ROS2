#ifndef TIMEPUBLISHER_H
#define TIMEPUBLISHER_H

#include <iostream>
#include <chrono>
#include "std_msgs/msg/header.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
using namespace std;

class TimePublisher : public rclcpp::Node {
private:
    int i_;
    rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Clock clock_;
    void publish_time_msg();

public:
    TimePublisher();

};

#endif