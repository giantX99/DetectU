
#ifndef RECORDSTRATEGY_H
#define RECORDSTRATEGY_H

#include "CameraStrategy.h"
#include "CameraViewer.h"

#include <QMediaRecorder>
#include <QUrl>

#include <iostream>
#include <exception>
#include <sstream>
#include <chrono>
#include <iomanip>

class RecordStrategy : public CameraStrategy
{
public:
    RecordStrategy();
    ~RecordStrategy();

    void set_cam_viewer(CameraViewer* c);
    void do_strat(bool t);

private:
    void set_output();
    void start_record();
    void stop_record();

    CameraViewer* cam_viewer = 0;
    QMediaRecorder recorder;
};

#endif // RECORDSTRATEGY_H
