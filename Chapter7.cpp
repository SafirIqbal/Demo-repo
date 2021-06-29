#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgDilate, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2); //For all contours//
	
	//Finding area of contour to filter out noise//

	for (int i = 0; i < contours.size(); i++) {
		string objectType;
		vector<Rect>  boundRect(contours.size());
		vector<vector<Point>> conPoly(contours.size()); //output of polygon approx having maximum size of contours//
		int area = contourArea(contours[i]);
		cout <<"Area of contour is: " << area << endl;
		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
		//Now we are approximating corner points so to determine shapes//
			cout << conPoly[i].size() << endl; //This will print out the approximated points found using conPoly//
			
											   
											   //Findind bounding box//

			boundRect[i] = boundingRect(conPoly[i]);
			


			int objCorner = int(conPoly[i].size());
			if (objCorner == 3) { objectType = "Tri"; }
			else if (objCorner == 4) {
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << "The aspect ratio is: " << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}

				else { objectType = "Rectangle"; }
			}
			else if (objCorner > 4 ) { objectType = "Circle"; }
			
			putText(img, objectType, { boundRect[i].x , boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 0.75, Scalar(0, 69, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2); //Only draw contours of objects except noise//
		}
	}
}



int main() {
	Mat imgGray, imgBlur, imgCanny, imgDilate;
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDilate, kernel);
	getContours(imgDilate, img);
	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDilate);*/
	waitKey(0);

	return 0;
}