
#ifndef DETECTBUTTON_H
#define DETECTBUTTON_H

#include <QPushButton>


class DetectButton : public QPushButton
{
public:
    DetectButton(QWidget* parent = 0);

private slots:
    void pressed();
    void released();
};

#endif // DETECTBUTTON_H
