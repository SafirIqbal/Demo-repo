#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;


int main() {

	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	VideoCapture cap(0);
	Mat img;
	Mat imgHSV, mask;

	//Color Detection Code//
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Minimum", "Trackbars", &hmin, 179);
	createTrackbar("Hue Maximum", "Trackbars", &hmax, 179);
	createTrackbar("Sat Minimum", "Trackbars", &smin, 255);
	createTrackbar("Sat Maximum", "Trackbars", &smax, 255);
	createTrackbar("Val Minimum", "Trackbars", &vmin, 255);
	createTrackbar("Val Minimum", "Trackbars", &vmax, 255);
	while (true) {
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);
		cout << hmin << ", " << smin << ", " << vmin << ", " << hmax << ", " << smax << ", " << vmax << endl;
		
		imshow("Webcam", img);
		imshow("Mask", mask);
		waitKey(1);

	}

	return 0;
}