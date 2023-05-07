
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
    ~CaptureStrategy();

    void set_cam_viewer(CameraViewer* c);
    void do_strat(bool t) override;

    static CaptureStrategy& getInstance();

    CaptureStrategy(CaptureStrategy const& ) = delete; // delete copy constructor;
    CaptureStrategy& operator=(CaptureStrategy const&) = delete; //delete copy assignment
    CaptureStrategy(CaptureStrategy &&) = delete; // delete move (transfer and delete original) constructor
    CaptureStrategy& operator = (CaptureStrategy &&) = delete; // delete move (transfer and delete original) assignment

private:
    CaptureStrategy();

    QString set_filename();
    void start_capture();

    CameraViewer* cam_viewer = 0;
    QImageCapture capture;
};

#endif // CAPTURESTRATEGY_H
