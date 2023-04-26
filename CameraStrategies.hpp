#pragma once
#include "CameraFunction.hpp"

class Detect : public CameraFunction{
    void start() override;
	void stop() override;
};

class Record : public CameraFunction{
    void start() override;
	void stop() override;
};
