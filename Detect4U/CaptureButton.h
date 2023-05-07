
#ifndef CAPTUREBUTTON_H
#define CAPTUREBUTTON_H

#include <QPushButton>

#include "CameraViewer.h"
#include "CaptureStrategy.h"


class CaptureButton : public QPushButton
{
public:
    CaptureButton(QWidget* parent = 0);
    ~CaptureButton();

    void set_capture(CameraViewer* c);
    CaptureStrategy* get_capture();

private:
    CaptureStrategy* m_capture = 0;
};

#endif // CAPTUREBUTTON_H
