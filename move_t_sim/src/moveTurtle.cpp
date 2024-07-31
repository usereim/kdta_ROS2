#include "movetSim/moveTurtle.hpp"

MoveTurtleSim::MoveTurtleSim()
: Node("moveTurtle_node"), i_(0)
    {
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", qos_profile);
        pub2_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle2/cmd_vel", qos_profile);
        timer_ = this->create_wall_timer(30ms, std::bind(&MoveTurtleSim::publish_turtlesim_msg,
        this));
    }

void MoveTurtleSim::publish_turtlesim_msg()
{
    auto msg = geometry_msgs::msg::Twist();
    auto msg2 = geometry_msgs::msg::Twist();
    msg.linear.x = execelaration;
    msg.angular.z = 1.8;
    msg2.linear.x = execelaration;
    msg2.angular.z = 2.8;

    pub_->publish(msg);
    pub2_->publish(msg2);
    execelaration += 0.01;
     if (execelaration > 3.0)
    {
        execelaration = 0.0;
    }
}