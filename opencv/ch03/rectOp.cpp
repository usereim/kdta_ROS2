#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data";

int main()
{
    //Rect ex
    Rect rc1;
    rc1.x = 1;
    rc1.y = 1;
    rc1.width = 10;
    rc1.height = 10;
    Rect rc2(20, 30, 500, 400);

    cout << rc2.tl() << endl;
    cout << rc2.br() << endl;

    //RotateRect ex
    Point pt1(10, 20);
    Size sz1(100, 100);
    
    RotatedRect rr1(pt1, sz1, 30);

    Point2f pts[4];
    rr1.points(pts);
    cout << pts[0] << endl;
    cout << pts[1] << endl;
    cout << pts[2] << endl;
    cout << pts[3] << endl;

    return 0;
}