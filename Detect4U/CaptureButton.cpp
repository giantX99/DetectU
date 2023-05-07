
#include "CaptureButton.h"

CaptureButton::CaptureButton(QWidget* parent) :
    QPushButton(parent)
{
    setText("Capture");
}

CaptureButton::~CaptureButton(){}

void CaptureButton::set_capture(CameraViewer* c) {
    m_capture.set_cam_viewer(c);
}

CaptureStrategy* CaptureButton::get_capture() { return &m_capture; }
