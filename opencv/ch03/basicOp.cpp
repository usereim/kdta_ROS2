#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data";

int main()
{
    //Point ex
    //Point pt1;
    Point2i pt1;
    pt1.x = 5;
    pt1.y = 10;
    Point pt2(6, 7);

    cout << pt1 << endl;
    cout << pt2 << endl;

    //Size ex
    Size sz1;
    sz1.height = 10;
    sz1.width = 20;
    Size sz2(50, 100);

    cout << sz1 << endl;
    cout << sz2 << endl;

    cout << "size1 : " << sz1.area() << ", size2: " << sz2.area() << endl;

    return 0;
}