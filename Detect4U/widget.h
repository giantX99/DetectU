
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
    Ui::Widget *ui;

private slots:

    void on_record_button_clicked(bool checked);
    void on_capture_button_clicked();
};

#endif // WIDGET_HPP
