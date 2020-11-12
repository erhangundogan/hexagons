hexagons
========

- Draws hexagons with [polylines](https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#gaa3c25f9fb764b6bef791bf034f6e26f5)
- Fills them with [fillConvexPoly](https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#ga9bb982be9d641dc51edd5e8ae3624e1f)
- Opens default camera for video capturing on screen with hexagons overlay

This code requires [OpenCV](https://github.com/opencv/opencv) and [cmake](https://cmake.org/install/) to be able to compile and run.

Try commands below to find out if you have opencv and cmake:

```bash
$ opencv_version
4.4.0

$ cmake --version
cmake version 3.18.4
```

Install & Run
=============

```
$ cmake .
$ make

$ build/hexagons
```

### Sample frame from real time video capture

![hexagons](https://github.com/erhangundogan/hexagons/blob/master/images/video-capture.png)
