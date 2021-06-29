#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
//
//int main() {
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	Mat imgCrop, imgResize;
//
//	resize(img, imgResize, Size(640 , 480));
//	imshow("Image Resize", imgResize);
//	imshow("Original", img);
//	waitKey(0);
//
//	return 0;
//}



int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgCrop;

	Rect roi(200, 40, 300, 350);
	imgCrop = img(roi);
	imshow("Original", img);
	imshow("Image Crop", imgCrop);
	waitKey(0);

	return 0;
}