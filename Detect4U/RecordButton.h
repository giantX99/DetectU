
#ifndef RECORDBUTTON_H
#define RECORDBUTTON_H

#include <QPushButton>

#include "CameraViewer.h"
#include "RecordStrategy.h"


class RecordButton : public QPushButton
{
public:
    RecordButton(QWidget* parent = 0);
    ~RecordButton();

    void set_recorder(CameraViewer* c);
    RecordStrategy* get_recorder();

private:
    RecordStrategy* m_recorder = 0;
};

#endif // RECORDBUTTON_H
