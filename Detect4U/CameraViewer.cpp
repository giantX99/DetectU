
#include "CameraViewer.h"

CameraViewer::CameraViewer(QWidget* parent) :
    QVideoWidget(parent)
{
    try {
        m_session = new QMediaCaptureSession;
        m_session->setCamera(m_camera = new QCamera(QMediaDevices::defaultVideoInput()));
        m_session->setVideoOutput(this);
    }
    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }

    this->show();
    m_camera->start(); // to start the camera

    if (!m_camera->isActive()) { throw std::runtime_error("COULD NOT LOAD CAMERA STREAM"); }
}


CameraViewer::~CameraViewer(){
    if (m_session && !m_camera) { delete m_session; }
    if (!m_session && m_camera) { delete m_camera; }
    if (m_session && m_camera) {
        delete m_session;
        delete m_camera;
    }
}


void CameraViewer::start_record() {

//    auto now = std::chrono::system_clock::now();
//    std::time_t time = std::chrono::system_clock::to_time_t(now);

//    std::stringstream ss;
//    ss << "Detect4U_Recording@";
//    ss << std::put_time(std::localtime(&time), "%Yy-%mm-%dd-%H-%M-%S");
//    ss << ".mp3";
//    std::string file_name = ss.str();
//    std::cout << "File Name: " << file_name << std::endl;
    std::string file_name = "c/test/test.mp3";
    m_session->setRecorder(&recorder);
//    recorder.setQuality(QMediaRecorder::HighQuality);
//    recorder.setOutputLocation(QUrl::fromLocalFile(QString::fromStdString(file_name)));
    try{
        recorder.setOutputLocation(QUrl::fromLocalFile(QString::fromStdString(file_name)));
    }
    catch (QMediaRecorder::Error e) {
        std::cout << "Error occurred" << std::endl;
        return;
    }

    recorder.record();
    std::cout << "RECORDING STARTED" << std::endl;
}

void CameraViewer::stop_record() {
    if (recorder.recorderState()) {
        recorder.stop();
        std::cout << "RECORDING STOPPED" << std::endl;
    }
}
