
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)//, m_camera(0)
{
    ui->setupUi(this);

    ui->record_button->set_recorder(ui->camera_viewer);
    ui->capture_button->set_capture(ui->camera_viewer);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_record_button_clicked(bool checked)
{
    ui->camera_viewer->set_strategy(ui->record_button->get_recorder());
    if (checked) { ui->camera_viewer->do_strategy(checked); }
    else { ui->camera_viewer->do_strategy(checked); }
}


void Widget::on_capture_button_clicked()
{
    ui->camera_viewer->set_strategy(ui->capture_button->get_capture());
    ui->camera_viewer->do_strategy(true);
}

