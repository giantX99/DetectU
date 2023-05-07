
#include "CaptureButton.h"

CaptureButton::CaptureButton(QWidget* parent) :
    QPushButton(parent)
{
    setText("Capture");
}

CaptureButton::~CaptureButton() { if (m_capture) { delete m_capture; } }

void CaptureButton::set_capture(CameraViewer* c) {
    m_capture = new CaptureStrategy;
    m_capture->set_cam_viewer(c);
}

CaptureStrategy* CaptureButton::get_capture() { return m_capture; }
