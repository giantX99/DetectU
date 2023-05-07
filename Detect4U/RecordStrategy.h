
#ifndef RECORDSTRATEGY_H
#define RECORDSTRATEGY_H

#include "CameraStrategy.h"

#include <QVideoWidget>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QCamera>
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

    void do_strat(bool t);

private:
    void set_output();
    void start_record();
    void stop_record();


    QCamera* m_camera = 0;
    QMediaCaptureSession* m_session = 0;
    QMediaRecorder recorder;
};

#endif // RECORDSTRATEGY_H
