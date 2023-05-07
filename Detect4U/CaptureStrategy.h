
#ifndef CAPTURESTRATEGY_H
#define CAPTURESTRATEGY_H

#include "CameraStrategy.h"
#include "CameraViewer.h"

#include <QImageCapture>

#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>

class CaptureStrategy : public CameraStrategy
{
public:
    CaptureStrategy();
    ~CaptureStrategy();

    void set_cam_viewer(CameraViewer* c);
    void do_strat(bool t) override;

private:
    QString set_filename();
    void start_capture();

    CameraViewer* cam_viewer = 0;
    QImageCapture capture;
};

#endif // CAPTURESTRATEGY_H
