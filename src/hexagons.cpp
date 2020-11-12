#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <random>

// change these for diff screen resolutions
#define w 1440
#define h 900

using namespace cv;
using namespace std;

void drawHexagon(Mat, Point, Scalar);
void drawHexagons(Mat, int);

int main(int argc, char* argv[]) {
  Size imageSize(w, h);
  Mat imageHexagons(imageSize, CV_8UC3);

  if (imageHexagons.empty())
  {
    cerr << "ERROR! Image cannot be created\n";
    return -1;
  }

  Mat dstImage, frame;
  VideoCapture capture;
  int factorDefault = 11; // increase/decrease space between hexagons
  int deviceID = 0; // specify your video capture device
  int apiID = cv::CAP_ANY;

  capture.set(VideoCaptureProperties::CAP_PROP_FRAME_WIDTH, w);
  capture.set(VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT, h);

  capture.open(deviceID, apiID);

  if (!capture.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }

  for (;;) {
    capture >> frame;

    if (frame.empty()) {
      cerr << "ERROR! blank frame grabbed\n";
      break;
    }

    imageHexagons = Scalar(0, 0, 0);
    dstImage = Scalar(0, 0, 0);

    drawHexagons(imageHexagons, factorDefault);
    resize(frame, frame, Size(w, h), 0, 0, INTER_CUBIC);
    frame.copyTo(dstImage, imageHexagons);
    imshow("Masked", dstImage);

    if (waitKey(5) >= 0)
      break;
  }

  return 0;
}

void drawHexagon(Mat image, Point p, Scalar color) {
  int thickness = 1;
  int lineType = LINE_AA;
  bool isClosed = true;
  Point p1 = Point( 30, 20);
  Point p2 = Point(  0, 20);
  Point p3 = Point(-30, 20);
  vector<Point> points;

  // hexagon points
  points.push_back(p);
  points.push_back(p += p1);
  points.push_back(p += p2);
  points.push_back(p += p3);
  points.push_back(p -= p1);
  points.push_back(p -= p2);
  points.push_back(p -= p3);

  // draws polygons
  polylines(image,
            points,
            isClosed,
            color,
            thickness,
            lineType);

   // fills polygons, you can remove this method to draw only edges
   fillConvexPoly(image,
                  points,
                  color,
                  lineType);
}

void drawHexagons(Mat image, int factor) {
  // change x, y, factor values to increase/decrease distance between hexagons
  int x = 3;
  int y = 2;
  Point s(-x * factor, -y * factor);

  for(int row = 0; s.y < h; row++) {
    for(int col = 0; s.x <= w; col++) {
      drawHexagon(image, s, Scalar(255, 255, 255));
      s.x += x * factor * 2;
    }
    s.y += y * factor * 2;
    s.x = row % 2 ? x * factor : 0;
  }
}