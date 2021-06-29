#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
//Warp Perspective (King) Card//
//int main() {
//	Mat imgwarp;
//	float w = 250, h = 350;
//
//	string path = "Resources/cards.jpg";
//	Mat img = imread(path);
//	Point2f src[4] = { {528,140},{769,188},{403,394},{676,458} };
//	Point2f dst[4] = { {0.0f , 0.0f},{w , 0.0f} , {0.0f , h} , {w ,h} };
//	Mat matrix = getPerspectiveTransform(src, dst);
//	warpPerspective(img, imgwarp, matrix, Point(w, h));
//
//	for showing circles around the snapping points//
//
//	for (int i = 0; i < 4; i++)
//	{
//		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
//
//	}
//
//	imshow("Image", img);
//	imshow("Image Warp", imgwarp);
//	waitKey(0);
//
//	return 0;
//}

//Warp Perspective Queen Card//

int main() {
	Mat imgwarp;
	float w = 250, h = 350;

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Point2f src[4] = { {62,326},{335,277},{89,634},{405,571} };
	Point2f dst[4] = { {0.0f , 0.0f},{w , 0.0f} , {0.0f , h} , {w ,h} };
	Mat matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgwarp, matrix, Point(w, h));

	//for showing circles around the snapping points//

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);

	}

	imshow("Image", img);
	imshow("Image Warp", imgwarp);
	waitKey(0);

	return 0;
}