#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string folder = "/home/jty6109/kdta_ROS2/opencv/data/";
int main()
{
    int key = 0;
    int i = 0;
    Mat img;
    img = imread(folder + "lenna.bmp");
    namedWindow("lenna");
    imshow("lenna", img);
    while (key != -1) {
        key = waitKey(0);
        cout << key << endl;
        if (key == 83) {
            i += 100;
            cout << i << endl;
            moveWindow("lenna", 0, i);
        }   
    }
    
    imshow("lenna", img);
    waitKey(0);

    return 0;
}