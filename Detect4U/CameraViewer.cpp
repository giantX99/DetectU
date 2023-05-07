
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
    if (m_session && m_camera && cam_strat) {
        delete m_session;
        delete m_camera;
        delete cam_strat;
    }
}


QCamera* CameraViewer::get_camera() { return m_camera; }
QMediaCaptureSession* CameraViewer::get_session() { return m_session; }


void CameraViewer::set_strategy(CameraStrategy* strategy){ cam_strat = strategy; }

void CameraViewer::do_strategy(bool t) {
    cam_strat->do_strat(t);
}
