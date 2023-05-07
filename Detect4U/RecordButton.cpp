
#include "RecordButton.h"

RecordButton::RecordButton(QWidget* parent) :
    QPushButton(parent)
{
    setText("Record");
}

RecordButton::~RecordButton() { if (m_recorder) { delete m_recorder; } }

void RecordButton::set_recorder(CameraViewer* c) {
    m_recorder = new RecordStrategy;
    m_recorder->set_cam_viewer(c);
}

RecordStrategy* RecordButton::get_recorder() { return m_recorder; }
