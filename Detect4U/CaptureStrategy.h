
#ifndef CAPTURESTRATEGY_H
#define CAPTURESTRATEGY_H

#include "CameraStrategy.h"

#include "CameraViewer.h"


class CaptureStrategy : public CameraStrategy
{
public:
    CaptureStrategy();
    ~CaptureStrategy();

    void set_cam_viewer(CameraViewer* c);
    void do_strat(bool t);

private:
    void set_output();
    void start_capture();

    CameraViewer* cam_viewer = 0;
};

#endif // CAPTURESTRATEGY_H
