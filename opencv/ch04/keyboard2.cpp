#include "opencv2/opencv.hpp"
#include <iostream>
#include <chrono>
#include <thread>

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
    Mat img = imread(folder + "lenna.bmp");
    Mat img2;
    int keycode;
    Scalar a(0, 0, 0);
    TickMeter tm;
    TickMeter tm2;

    namedWindow("img");
    imshow("img", img);
    float fps = 30.0;
    int delay = cvRound(1000/fps);

    while (true) {
        tm.start();
        tm2.start();

        keycode = waitKey(10);
        if (keycode != -1) {
            cout << "keycode : " << keycode << endl;
        }
        if (keycode == 27) {
            break;
        }
        if (keycode == 'i' || keycode == 'I') {
            img = ~img;
            imshow("img", img);
        }
        if (keycode == 'a' || keycode == 'A') {
            a = a + Scalar(1, 1, 1);
            img2 = img + a;
            imshow("img", img2);
        }
        if (keycode == 'b' || keycode == 'b') {
            a = a - Scalar(1, 1, 1);
            img2 = img + a;
            imshow("img", img2);
        }

        tm.stop();
        cout << "tm.getFPS() : " << tm.getFPS() << endl;
        if (tm.getFPS() > fps) {
            auto sleep_duration = static_cast<int>(1000.0 * (tm.getFPS() - fps) / tm.getFPS() / fps);
            this_thread::sleep_for(chrono::milliseconds(sleep_duration));
        }
        tm2.stop();
        cout << "tm.getFPS() : " << tm2.getFPS() << endl;
    }

    imshow("img", img);
    waitKey(0);
    return 0;
}