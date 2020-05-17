#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <random>

#define w 1280
#define h 1024

using namespace cv;
using namespace std;

void drawHexagons(Mat, Point, Scalar);

int main() {
  Size imageSize(w, h);
  Mat image(imageSize, CV_8UC3);

  if (image.empty())
  {
    cout << "Error : Image cannot be created..!!" << endl;
    system("pause");
    return -1;
  }
  cout << "Press any key to regenerate OR press 'q' to exit!" << endl;

  namedWindow("hexagons", WINDOW_AUTOSIZE);

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> shouldShow(0, 1);

  for(;;) {
    int x = 3;
    int y = 2;
    int factor = 10;
    Point s(-x * factor, -y * factor);

    for(int row = 0; s.y < h; row++) {
      for(int col = 0; s.x <= w; col++) {
        // you can remove this method to draw full screen
        bool b = shouldShow(gen);
        if (b) {
          // you can randomize Scalar BGR
          drawHexagons(image, s, Scalar(255, 255, 255));
        }
        s.x += x * factor * 2;
      }
      s.y += y * factor * 2;
      s.x = row % 2 ? -x * factor : 0;
    }

    imshow("hexagons", image);

    char c = waitKey(0);
    if (c == 'q') {
      break;
    }
    image.setTo(Scalar::all(0));
  }

  return 0;
}

void drawHexagons(Mat image, Point p, Scalar color) {
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

   // fills polygons
   // you can remove this to draw only edges
   fillConvexPoly(image,
                  points,
                  color,
                  lineType);
}
