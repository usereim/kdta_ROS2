#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "building.jpg", IMREAD_GRAYSCALE);

    Mat edge;
    Canny(img, edge, 50, 150);
    
    vector<Vec4i> lines;
    HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
    cvtColor(img, img, COLOR_GRAY2BGR);

    for (auto lineP : lines) {
        line(img, Point(lineP[0], lineP[1]), Point(lineP[2], lineP[3]), Scalar(0, 0, 255), 2);
    }

    imshow("img", img);
    imshow("edge", edge);
    
    waitKey(0);

    return 0;
}