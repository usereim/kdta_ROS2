#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "kids.png");
    
    CascadeClassifier classifier(folder + "haarcascade_frontalface_default.xml");
    vector<Rect> face;
    classifier.detectMultiScale(img, face);

    for (auto rect : face) {
        rectangle(img, rect, Scalar(0, 0, 255), 3);
    }

    imshow("img", img);

    waitKey(0);
    return 0;
}