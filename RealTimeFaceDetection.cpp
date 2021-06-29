#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> //Used for detecting face/eyes.....//
#include <iostream>

using namespace cv;
using namespace std;


///////////////  Face Detection  //////////////////////

int main() {

    VideoCapture cap(0);
    Mat img;


    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    if (faceCascade.empty()) { cout << "XML file is not loaded" << endl; }
    vector<Rect> faces;

    while (true) {

        cap.read(img);
        faceCascade.detectMultiScale(img, faces, 1.1, 10);

        for (int i = 0; i < faces.size(); i++) {

            //Cropping and saving the face//

            Mat imgCrop = img(faces[i]);
            imwrite("Resources/faces/" + to_string(i) + ".png", imgCrop);
            

            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
            imshow("Image Crop", imgCrop);


        }



        imshow("Image", img);
      
        waitKey(1); //This adds a delay where '0' means infinity otherwise the image will close automatically//

    }
    return 0;
}

