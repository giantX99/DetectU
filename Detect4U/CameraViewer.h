
#ifndef CAMERAVIEWER_H
#define CAMERAVIEWER_H

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


class CameraViewer : public QVideoWidget
{
public:
    CameraViewer(QWidget* parent = 0);
    ~CameraViewer();

public slots:
    void start_record();
    void stop_record();

private:
    //CameraStrategy Recorder;
    QCamera* m_camera = 0;
    QMediaCaptureSession* m_session = 0;
    QMediaRecorder recorder;
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
