hexagons
========

Draw hexagons with [polylines](https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#gaa3c25f9fb764b6bef791bf034f6e26f5) and fills them with [fillConvexPoly](https://docs.opencv.org/master/d6/d6e/group__imgproc__draw.html#ga9bb982be9d641dc51edd5e8ae3624e1f) by using OpenCV. It's an example tointroduction to the drawing.

This code requires [OpenCV](https://github.com/opencv/opencv) and [cmake](https://cmake.org/install/) to be able to compile and run.

Try commands below to find out if you have opencv and cmake:

```bash
$ opencv_version
4.3.0-dev

$ cmake --version
cmake version 3.17.1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

Install & Run
=============

```
$ cmake .
-- The C compiler identification is AppleClang 11.0.3.11030032
-- The CXX compiler identification is AppleClang 11.0.3.11030032
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenCV: /usr/local/Cellar/opencv/4.3.0 (found version "4.3.0")
-- OpenCV library status:
--     config: /usr/local/lib/cmake/opencv4
--     version: 4.3.0
--     libraries: opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio
--     include path: /usr/local/Cellar/opencv/4.3.0/include/opencv4
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/foo/hexagons

$ make
[ 50%] Building CXX object CMakeFiles/hexagons.dir/src/hexagons.cpp.o
[100%] Linking CXX executable build/hexagons
[100%] Built target hexagons

$ ./build/hexagons
```

`polylines` with `fillConvexPoly`

![hexagons](https://github.com/erhangundogan/hexagons/blob/master/images/hexagons1.png)

only `polylines`

![hexagons](https://github.com/erhangundogan/hexagons/blob/master/images/hexagons2.png)
