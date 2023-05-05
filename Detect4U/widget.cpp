
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)//, m_camera(0)
{
    ui->setupUi(this);

    //record button function:
//    connect(ui->record_button, SIGNAL(pressed()),
//            ui->camera_viewer, SLOT(start_record()));
//    connect(ui->record_button, SIGNAL(released()),
//            ui->camera_viewer, SLOT(stop_record()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_record_button_clicked(bool checked)
{
    if (checked) { ui->camera_viewer->start_record(); }
    else { ui->camera_viewer->stop_record(); }
}

