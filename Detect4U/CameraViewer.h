
#ifndef CAMERAVIEWER_H
#define CAMERAVIEWER_H

#include <QVideoWidget>

#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <QCamera>

#include "CameraStrategy.h"


class CameraViewer : public QVideoWidget
{
public:
    CameraViewer(QWidget* parent = 0);
    ~CameraViewer();

    void set_strategy();
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




//CODE FOR QImage to cv::mat:

//QVideoFrame FaceRecognitionFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags)
//{
//    input->map(QAbstractVideoBuffer::ReadOnly);
//    QImage img( input->bits(),
//               input->width(),
//               input->height(),
//               input->bytesPerLine(),
//               QVideoFrame::imageFormatFromPixelFormat(input->pixelFormat()));
//    cv::Mat mat(img.height(), img.width(), CV_8UC3, img.bits(),img.bytesPerLine());
//    cv::circle(mat, cv::Point(100, 100), 35, cv::Scalar(0,0,255), 2, CV_AA );
//    QImage tmp((uchar*)mat.data, mat.cols, mat.rows, QImage::Format_RGB888);
//    QVideoFrame *output = new QVideoFrame(tmp);
//    input->unmap();
//    return *output;
//}
