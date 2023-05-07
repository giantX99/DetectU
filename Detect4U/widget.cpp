
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)//, m_camera(0)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_record_button_clicked(bool checked)
{
    if (checked) { ui->camera_viewer->do_strategy(true); }
    else { ui->camera_viewer->do_strategy(false); }
}

