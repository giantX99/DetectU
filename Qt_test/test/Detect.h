
#ifndef DETECT_H
#define DETECT_H

#include "CameraFunction.h"
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>


class Detect : CameraFunction {
protected:
    void set_up();

public:
    void start();
    void stop();
};

#endif // DETECT_H
