/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *widget_3;
    QPushButton *pushButton_7;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(1280, 720);
        admin->setMinimumSize(QSize(1280, 720));
        admin->setMaximumSize(QSize(1280, 720));
        admin->setBaseSize(QSize(1280, 720));
        widget = new QWidget(admin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, 0, 1291, 721));
        widget->setStyleSheet(QString::fromUtf8("	QWidget#widget\n"
"{\n"
"	background-image: url(:/Admin inter.png);\n"
"}"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(440, 260, 801, 431));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 251, 201));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 0, 251, 201));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 0, 251, 201));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(550, 230, 251, 201));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(280, 230, 251, 201));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 230, 251, 201));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(1159, 110, 111, 41));
        pushButton_7 = new QPushButton(widget_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(0, 0, 111, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "MED++", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
