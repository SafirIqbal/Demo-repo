#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
vector<vector<int>> newPoints;

Point getContours(Mat imgDilate) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2); //For all contours//

	//Finding area of contour to filter out noise//
	Point myPoint(0, 0);
	for (int i = 0; i < contours.size(); i++) {
		string objectType;
		vector<Rect>  boundRect(contours.size());
		vector<vector<Point>> conPoly(contours.size()); //output of polygon approx having maximum size of contours//
		int area = contourArea(contours[i]);
		cout << "Area of contour is: " << area << endl;
		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//Now we are approximating corner points so to determine shapes//
			cout << conPoly[i].size() << endl; //This will print out the approximated points found using conPoly//


											   //Findind bounding box//

			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2); //Only draw contours of objects except noise//
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	return myPoint;
}







vector<vector<int>> myColors{ {129, 52, 0, 179, 255, 156},
	{44, 90, 0, 93, 255, 255} }; //Red and Green color from colorPicker// 

vector<Scalar> myColorsValues{ {0,0,255}, {0 ,255,0} }; //Red and Green values that needs to be shown//

vector<vector<int>> findcolor(Mat img) {

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++) {
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);

	Point myPoint =	getContours(mask);
	if (myPoint.x != 0 && myPoint.y != 0) {
		newPoints.push_back({ myPoint.x,myPoint.y,i });
	}
	}

	return newPoints;
}


void drawCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorsValues) {
	for (int i = 0; i < newPoints.size(); i++) {

		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorsValues[newPoints[i][2]],FILLED);

			}

}
int main() {
	VideoCapture cap(0);
	
	
	while (true) {
	
 	cap.read(img);
	newPoints = findcolor(img);
	drawCanvas(newPoints, myColorsValues);
	imshow("Image", img);
	waitKey(1);
	
	}
	
	
	return 0;
}