//파일 읽어오기
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    
    Mat lennaimg = imread(folder + "lena.bmp");
    Mat maskSmile = imread(folder + "mask_smile.bmp", IMREAD_GRAYSCALE);
    
    lennaimg.setTo(yellow, maskSmile);
    imshow("img", lennaimg);
    waitKey(0);

    Mat airplaneImg = imread(folder + "airplane.bmp");
    Mat maskAirplane = imread(folder + "mask_plane.bmp");
    Mat sky = imread(folder + "field.bmp");

    airplaneImg .copyTo(sky, maskAirplane);

    imshow("img", sky);
    waitKey(0);

    return 0;
}