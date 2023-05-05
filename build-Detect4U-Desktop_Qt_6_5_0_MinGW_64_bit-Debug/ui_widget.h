/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "CameraViewer.h"
#include "DetectButton.h"
#include "RecordButton.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    DetectButton *detect_button;
    RecordButton *record_button;
    CameraViewer *camera_viewer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(443, 369);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 0, 401, 291));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 240, 381, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        detect_button = new DetectButton(layoutWidget);
        detect_button->setObjectName("detect_button");
        detect_button->setCheckable(true);
        detect_button->setChecked(false);

        horizontalLayout->addWidget(detect_button);

        record_button = new RecordButton(layoutWidget);
        record_button->setObjectName("record_button");
        record_button->setCheckable(true);
        record_button->setChecked(false);

        horizontalLayout->addWidget(record_button);

        camera_viewer = new CameraViewer(groupBox);
        camera_viewer->setObjectName("camera_viewer");
        camera_viewer->setGeometry(QRect(9, 29, 381, 201));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Detect4U", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "CameraView", nullptr));
        detect_button->setText(QCoreApplication::translate("Widget", "Detect", nullptr));
        record_button->setText(QCoreApplication::translate("Widget", "Record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
