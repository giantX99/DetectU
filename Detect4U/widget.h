
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include <QMultimedia>
//#include <QCamera>
//#include <QCameraViewfinder>
#include <QLabel>
#include <QPushButton>
//#include <opencv2/opencv.hpp>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    //QLabel *m_display;
    //QPushButton *m_recordButton;
    //QPushButton *m_detectButton;
    //cv::VideoCapture m_camera;
    Ui::Widget *ui;

private slots:

    void on_record_button_clicked(bool checked);
};

#endif // WIDGET_HPP
