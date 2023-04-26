#pragma once
#include <iostream>

class CameraFunction{

    CameraFunction(); // intialize open cv and open camera
    virtual void start();
	virtual void stop();
    virtual ~CameraFunction(){};

};