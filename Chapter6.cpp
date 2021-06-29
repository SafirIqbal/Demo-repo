#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Color Detection...//
int main() {
	
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	Mat mask;
	Mat imgHSV;
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Minimum", "Trackbars", &hmin, 179);
	createTrackbar("Hue Maximum", "Trackbars", &hmax, 179);
	createTrackbar("Sat Minimum", "Trackbars", &smin, 255);
	createTrackbar("Sat Maximum", "Trackbars", &smax, 255);
	createTrackbar("Val Minimum", "Trackbars", &vmin, 255);
	createTrackbar("Val Minimum", "Trackbars", &vmax, 255);
	while (true) {
		Scalar lowerlimit(hmin, smin, vmin);
		Scalar upperlimit(hmax, smax, vmax);
		inRange(imgHSV, lowerlimit, upperlimit, mask);



		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}
	return 0;
}