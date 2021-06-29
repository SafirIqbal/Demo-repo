#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//Color---- Grayscale//

//int main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	Mat imgGray;
//	cvtColor(img, imgGray, COLOR_BGR2GRAY);
//	imshow("Image",img);
//	imshow("Image Gray",imgGray);
//	waitKey(0);
//
//	return 0;
//}


//Adding Blur//

//int main() {
//	
//		string path = "Resources/test.png";
//		Mat img = imread(path);
//		Mat imgBlur;
//		GaussianBlur(img, imgBlur, Size(7,7), 5, 0);
//		imshow("Image",img);
//		imshow("Image Blur",imgBlur);
//		waitKey(0);
//	
//		return 0;
//	}


//Edge detector//
//int main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	Mat imgBlur, imgCanny;
//	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  //Before Canny, a small amount of Blur is good practice//
//	Canny(img, imgCanny, 50, 150);
//	imshow("Image", img);
//	imshow("Image Blur", imgBlur);
//	imshow("Image Canny", imgCanny);
//	waitKey(0);
//
//	return 0;
//}
//


//Edge Dilation/Erosion//
int main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgBlur, imgCanny, imgDil, imgErode;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  //Before Canny, a small amount of Blur is good practice//
	Canny(img, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);
	imshow("Image", img);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erosion", imgErode);
	waitKey(0);

	return 0;
}



