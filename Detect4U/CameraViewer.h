
#ifndef CAMERAVIEWER_H
#define CAMERAVIEWER_H

#include <QVideoWidget>

#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QCamera>

#include <exception>
#include <iostream>
#include "CameraStrategy.h"


class CameraViewer : public QVideoWidget
{
public:
    CameraViewer(QWidget* parent = 0);
    ~CameraViewer();

    void set_strategy(CameraStrategy* strategy);
    QCamera* get_camera();
    QMediaCaptureSession* get_session();

public slots:
    void do_strategy(bool t);

private:
    CameraStrategy *cam_strat = 0;
    QCamera* m_camera = 0;
    QMediaCaptureSession* m_session = 0;
};

#endif // CAMERAVIEWER_H

