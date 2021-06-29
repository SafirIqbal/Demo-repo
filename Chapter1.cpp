#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////
//
//int main() {
//
//    string path = "Resources/test.png";
//    Mat img = imread(path);
//    imshow("Image", img);
//    waitKey(0); //This adds a delay where '0' means infinity otherwise the image will close automatically//
//    return 0;
//
//}



/////////////////  Video  //////////////////////


//int main() {
//
//	string path = "Resources/test_video.mp4";
//
//		VideoCapture cap(path);
//		Mat img;
//
//	while (true) {
//
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(1);
//
//
//
//}
//

	/////////////////  Webcam  //////////////////////

//
//	int main() {
//
//
//		VideoCapture cap(0);
//		Mat img;
//
//		while (true) {
//
//			cap.read(img);
//			imshow("Image", img);
//			waitKey(1);
//
//
//				}
//
//
//
//
//	return 0;
//}


//Practice//
//Images//

//int main() {
//
//	string path = "Resources/test.png";
//	Mat img;
//	img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//
//	return 0;
//}



//Video/Webcam Practice//


int main() {

	/*string path = "Resources/test_video.mp4";*/
	Mat img;
	VideoCapture cap(0);


	while(true){
	
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	
	}




	return 0;
}


