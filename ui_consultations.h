/********************************************************************************
** Form generated from reading UI file 'consultations.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTATIONS_H
#define UI_CONSULTATIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Consultations
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QLineEdit *line_reff;
    QLineEdit *line_pat;
    QLineEdit *line_sym;
    QLineEdit *line_exa;
    QLineEdit *line_res;
    QLineEdit *line_dia;
    QWidget *widget_5;
    QPushButton *pushButton;
    QWidget *widget_6;
    QPushButton *Ajouter;
    QDateEdit *dateEdit;
    QTextEdit *textEdit1;
    QPushButton *imprimer;
    QComboBox *comboBox_2;
    QPushButton *sauvegarder;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *diagnostique;
    QWidget *tab_2;
    QWidget *widget_2;
    QLineEdit *idd;
    QLineEdit *res_exam;
    QLineEdit *symp;
    QLineEdit *diag;
    QLineEdit *reff_const;
    QLineEdit *exam;
    QPushButton *pushButton_3;
    QPushButton *modifier_consultation;
    QDateEdit *dateEdit_2;
    QComboBox *comboBox_3;
    QLabel *lc1;
    QPushButton *choisir;
    QPushButton *actualiser;
    QWidget *tab_3;
    QWidget *widget_3;
    QLineEdit *reff;
    QPushButton *pushButton_5;
    QPushButton *supprimer_consultation;
    QLabel *lc_2;
    QComboBox *supprimer;
    QWidget *tab_4;
    QWidget *widget_4;
    QTableView *TabConsultation;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QRadioButton *tri_date;
    QRadioButton *tri_reff;
    QRadioButton *tri_id;
    QLabel *lc_3;
    QPushButton *rechercher;
    QLineEdit *reff_consultation;
    QLabel *label;

    void setupUi(QDialog *Consultations)
    {
        if (Consultations->objectName().isEmpty())
            Consultations->setObjectName(QString::fromUtf8("Consultations"));
        Consultations->resize(1280, 720);
        Consultations->setMinimumSize(QSize(1280, 720));
        Consultations->setMaximumSize(QSize(1280, 720));
        Consultations->setBaseSize(QSize(1280, 720));
        tabWidget = new QTabWidget(Consultations);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1281, 721));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"Q"
                        "TabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1281, 701));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget\n"
"{\n"
"	background-image: url(:/Ajouter Consultation.png);\n"
"}"));
        line_reff = new QLineEdit(widget);
        line_reff->setObjectName(QString::fromUtf8("line_reff"));
        line_reff->setGeometry(QRect(150, 229, 171, 21));
        line_reff->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        line_pat = new QLineEdit(widget);
        line_pat->setObjectName(QString::fromUtf8("line_pat"));
        line_pat->setGeometry(QRect(150, 290, 171, 21));
        line_sym = new QLineEdit(widget);
        line_sym->setObjectName(QString::fromUtf8("line_sym"));
        line_sym->setGeometry(QRect(490, 290, 231, 31));
        line_sym->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        line_exa = new QLineEdit(widget);
        line_exa->setObjectName(QString::fromUtf8("line_exa"));
        line_exa->setGeometry(QRect(250, 340, 471, 31));
        line_exa->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        line_exa->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        line_res = new QLineEdit(widget);
        line_res->setObjectName(QString::fromUtf8("line_res"));
        line_res->setGeometry(QRect(360, 490, 361, 41));
        line_res->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        line_res->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        line_dia = new QLineEdit(widget);
        line_dia->setObjectName(QString::fromUtf8("line_dia"));
        line_dia->setGeometry(QRect(180, 630, 281, 31));
        line_dia->setStyleSheet(QString::fromUtf8("QLineEdit:read-only {\n"
"background: lightblue;\n"
"}"));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(1150, 80, 120, 41));
        pushButton = new QPushButton(widget_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(1140, 410, 120, 41));
        Ajouter = new QPushButton(widget_6);
        Ajouter->setObjectName(QString::fromUtf8("Ajouter"));
        Ajouter->setGeometry(QRect(0, 0, 121, 41));
        Ajouter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Ajouter->setIcon(icon);
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(560, 230, 111, 22));
        dateEdit->setStyleSheet(QString::fromUtf8("\n"
"QDateEdit::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 15px;\n"
" \n"
"	border-left-width: 1px;\n"
"	border-left-color: darkgray;\n"
"	border-left-style: solid;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}\n"
"QDateEdit {\n"
"	border: 2px solid lightgray;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"\n"
""));
        textEdit1 = new QTextEdit(widget);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setGeometry(QRect(850, 430, 251, 241));
        textEdit1->setStyleSheet(QString::fromUtf8("/*border-width:2px;\n"
"border-style:solid;\n"
"border-color:darkblue;*/\n"
"QTextEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        imprimer = new QPushButton(widget);
        imprimer->setObjectName(QString::fromUtf8("imprimer"));
        imprimer->setGeometry(QRect(1120, 580, 93, 28));
        imprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"QPushButton:open { /* when the button has its menu open */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    image: url(menu_indicator.png);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"QP"
                        "ushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"    position: relative;\n"
"    top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
"}"));
        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 290, 171, 22));
        comboBox_2->setStyleSheet(QString::fromUtf8("border-width:2px;\n"
"border-style:solid;\n"
"border-color:darkblue;\n"
"\n"
"border-radius: 3px;\n"
"padding: 1px 18px 1px 3px;\n"
"min-width: 6em;\n"
"\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                       stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                       stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"\n"
"\n"
"padding-top: 3px;\n"
"padding-left: 4px;\n"
"\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 15px;\n"
"\n"
"border-left-width: 1px;\n"
"border-left-color: darkgray;\n"
"border-left-style: solid; \n"
"border-top-right-radius: 3px; \n"
"border-bottom-right-radius: 3px;\n"
"\n"
"top: 1px;\n"
"left: 1px;\n"
"\n"
"border: 2px solid darkgray;\n"
"selection-background-color: lightgray;"));
        sauvegarder = new QPushButton(widget);
        sauvegarder->setObjectName(QString::fromUtf8("sauvegarder"));
        sauvegarder->setGeometry(QRect(1120, 540, 93, 28));
        sauvegarder->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"QPushButton:open { /* when the button has its menu open */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    image: url(menu_indicator.png);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"QP"
                        "ushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"    position: relative;\n"
"    top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
"}"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(930, 390, 91, 20));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 0, 341, 41));
        diagnostique = new QComboBox(widget);
        diagnostique->setObjectName(QString::fromUtf8("diagnostique"));
        diagnostique->setGeometry(QRect(180, 630, 281, 31));
        diagnostique->setStyleSheet(QString::fromUtf8("border-width:2px;\n"
"border-style:solid;\n"
"border-color:darkblue;\n"
"\n"
"border-radius: 3px;\n"
"padding: 1px 18px 1px 3px;\n"
"min-width: 6em;\n"
"\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                       stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                       stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"\n"
"\n"
"padding-top: 3px;\n"
"padding-left: 4px;\n"
"\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 15px;\n"
"\n"
"border-left-width: 1px;\n"
"border-left-color: darkgray;\n"
"border-left-style: solid; \n"
"border-top-right-radius: 3px; \n"
"border-bottom-right-radius: 3px;\n"
"\n"
"top: 1px;\n"
"left: 1px;\n"
"\n"
"border: 2px solid darkgray;\n"
"selection-background-color: lightgray;"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 1281, 701));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget#widget_2\n"
"{\n"
"	background-image: url(:/ModifierConsultation.png);\n"
"}"));
        idd = new QLineEdit(widget_2);
        idd->setObjectName(QString::fromUtf8("idd"));
        idd->setGeometry(QRect(150, 300, 171, 31));
        idd->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"\n"
"}*/\n"
"\n"
""));
        res_exam = new QLineEdit(widget_2);
        res_exam->setObjectName(QString::fromUtf8("res_exam"));
        res_exam->setGeometry(QRect(370, 510, 351, 41));
        res_exam->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        res_exam->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        symp = new QLineEdit(widget_2);
        symp->setObjectName(QString::fromUtf8("symp"));
        symp->setGeometry(QRect(510, 300, 231, 31));
        symp->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        diag = new QLineEdit(widget_2);
        diag->setObjectName(QString::fromUtf8("diag"));
        diag->setGeometry(QRect(190, 640, 241, 31));
        diag->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        reff_const = new QLineEdit(widget_2);
        reff_const->setObjectName(QString::fromUtf8("reff_const"));
        reff_const->setGeometry(QRect(150, 250, 171, 21));
        exam = new QLineEdit(widget_2);
        exam->setObjectName(QString::fromUtf8("exam"));
        exam->setGeometry(QRect(230, 360, 361, 41));
        exam->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        exam->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1160, 80, 111, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        modifier_consultation = new QPushButton(widget_2);
        modifier_consultation->setObjectName(QString::fromUtf8("modifier_consultation"));
        modifier_consultation->setGeometry(QRect(1150, 410, 121, 41));
        modifier_consultation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        dateEdit_2 = new QDateEdit(widget_2);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(560, 240, 151, 31));
        dateEdit_2->setStyleSheet(QString::fromUtf8("\n"
"QDateEdit::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 15px;\n"
" \n"
"	border-left-width: 1px;\n"
"	border-left-color: darkgray;\n"
"	border-left-style: solid;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}\n"
"QDateEdit {\n"
"	border: 2px solid lightgray;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"\n"
""));
        comboBox_3 = new QComboBox(widget_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 250, 171, 22));
        comboBox_3->setStyleSheet(QString::fromUtf8("border-width:2px;\n"
"border-style:solid;\n"
"border-color:darkblue;\n"
"\n"
"border-radius: 3px;\n"
"padding: 1px 18px 1px 3px;\n"
"min-width: 6em;\n"
"\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                       stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                       stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"\n"
"\n"
"padding-top: 3px;\n"
"padding-left: 4px;\n"
"\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 15px;\n"
"\n"
"border-left-width: 1px;\n"
"border-left-color: darkgray;\n"
"border-left-style: solid; \n"
"border-top-right-radius: 3px; \n"
"border-bottom-right-radius: 3px;\n"
"\n"
"top: 1px;\n"
"left: 1px;\n"
"\n"
"border: 2px solid darkgray;\n"
"selection-background-color: lightgray;\n"
"\n"
""));
        lc1 = new QLabel(widget_2);
        lc1->setObjectName(QString::fromUtf8("lc1"));
        lc1->setGeometry(QRect(350, 0, 291, 41));
        choisir = new QPushButton(widget_2);
        choisir->setObjectName(QString::fromUtf8("choisir"));
        choisir->setGeometry(QRect(400, 180, 121, 41));
        choisir->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        actualiser = new QPushButton(widget_2);
        actualiser->setObjectName(QString::fromUtf8("actualiser"));
        actualiser->setGeometry(QRect(360, 180, 31, 31));
        actualiser->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        reff_const->raise();
        idd->raise();
        res_exam->raise();
        symp->raise();
        diag->raise();
        exam->raise();
        pushButton_3->raise();
        modifier_consultation->raise();
        dateEdit_2->raise();
        comboBox_3->raise();
        lc1->raise();
        choisir->raise();
        actualiser->raise();
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 1281, 691));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget#widget_3\n"
"{\n"
"	background-image: url(:/SuppConst.png);\n"
"}"));
        reff = new QLineEdit(widget_3);
        reff->setObjectName(QString::fromUtf8("reff"));
        reff->setGeometry(QRect(340, 350, 251, 31));
        reff->setStyleSheet(QString::fromUtf8("QLineEdit:read-only {\n"
"background: lightblue;\n"
"}"));
        reff->setClearButtonEnabled(true);
        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1150, 80, 111, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        supprimer_consultation = new QPushButton(widget_3);
        supprimer_consultation->setObjectName(QString::fromUtf8("supprimer_consultation"));
        supprimer_consultation->setGeometry(QRect(1120, 640, 121, 41));
        supprimer_consultation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        lc_2 = new QLabel(widget_3);
        lc_2->setObjectName(QString::fromUtf8("lc_2"));
        lc_2->setGeometry(QRect(410, 0, 291, 41));
        supprimer = new QComboBox(widget_3);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setGeometry(QRect(340, 350, 251, 31));
        supprimer->setStyleSheet(QString::fromUtf8("border-width:2px;\n"
"border-style:solid;\n"
"border-color:darkblue;\n"
"\n"
"border-radius: 3px;\n"
"padding: 1px 18px 1px 3px;\n"
"min-width: 6em;\n"
"\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                       stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                       stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
"\n"
"\n"
"padding-top: 3px;\n"
"padding-left: 4px;\n"
"\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 15px;\n"
"\n"
"border-left-width: 1px;\n"
"border-left-color: darkgray;\n"
"border-left-style: solid; \n"
"border-top-right-radius: 3px; \n"
"border-bottom-right-radius: 3px;\n"
"\n"
"top: 1px;\n"
"left: 1px;\n"
"\n"
"border: 2px solid darkgray;\n"
"selection-background-color: lightgray;\n"
"\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        widget_4 = new QWidget(tab_4);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(-20, 0, 1281, 691));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget#widget_4 \n"
"{\n"
"	background-image: url(:/AfficherCnst.png);\n"
"}"));
        TabConsultation = new QTableView(widget_4);
        TabConsultation->setObjectName(QString::fromUtf8("TabConsultation"));
        TabConsultation->setGeometry(QRect(90, 240, 981, 291));
        TabConsultation->setStyleSheet(QString::fromUtf8("QTableView QTableCornerButton::section {\n"
"    background: red;\n"
"    border: 2px outset red;\n"
"}\n"
"QTableView {\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                stop: 0 #FF92BB, stop: 1 gray);\n"
"}\n"
" QScrollBar:vertical {\n"
"     border: 2px solid grey;\n"
"     background: #32CC99;\n"
"     width: 15px;\n"
"     margin: 22px 0 22px 0;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background: white;\n"
"     min-height: 20px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     border: 2px solid grey;\n"
"     background: #32CC99;\n"
"     height: 20px;\n"
"     subcontrol-position: bottom;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
" QScrollBar::sub-line:vertical {\n"
"     border: 2px solid grey;\n"
"     background: #32CC99;\n"
"     height: 20px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     border: 2"
                        "px solid grey;\n"
"     width: 3px;\n"
"     height: 3px;\n"
"     background: white;\n"
" }\n"
"\n"
" QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"     background: none;\n"
" }\n"
"\n"
""));
        pushButton_7 = new QPushButton(widget_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1150, 80, 111, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#AARRGGBB ;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 200, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(16);
        label_2->setFont(font);
        tri_date = new QRadioButton(widget_4);
        tri_date->setObjectName(QString::fromUtf8("tri_date"));
        tri_date->setGeometry(QRect(230, 200, 95, 20));
        tri_date->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        tri_reff = new QRadioButton(widget_4);
        tri_reff->setObjectName(QString::fromUtf8("tri_reff"));
        tri_reff->setGeometry(QRect(350, 200, 95, 20));
        tri_reff->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}"));
        tri_id = new QRadioButton(widget_4);
        tri_id->setObjectName(QString::fromUtf8("tri_id"));
        tri_id->setGeometry(QRect(480, 200, 95, 20));
        tri_id->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 13px;\n"
"    height: 13px;\n"
"}"));
        lc_3 = new QLabel(widget_4);
        lc_3->setObjectName(QString::fromUtf8("lc_3"));
        lc_3->setGeometry(QRect(370, 0, 391, 41));
        rechercher = new QPushButton(widget_4);
        rechercher->setObjectName(QString::fromUtf8("rechercher"));
        rechercher->setGeometry(QRect(1050, 190, 93, 28));
        rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}\n"
"QPushButton:open { /* when the button has its menu open */\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"    image: url(menu_indicator.png);\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"QP"
                        "ushButton::menu-indicator:pressed, QPushButton::menu-indicator:open {\n"
"    position: relative;\n"
"    top: 2px; left: 2px; /* shift the arrow by 2 px */\n"
"}"));
        reff_consultation = new QLineEdit(widget_4);
        reff_consultation->setObjectName(QString::fromUtf8("reff_consultation"));
        reff_consultation->setGeometry(QRect(916, 190, 113, 22));
        reff_consultation->setStyleSheet(QString::fromUtf8("/*QLineEdit:read-only {\n"
"background: lightblue;\n"
"}*/\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(740, 190, 131, 20));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Consultations);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Consultations);
    } // setupUi

    void retranslateUi(QDialog *Consultations)
    {
        Consultations->setWindowTitle(QCoreApplication::translate("Consultations", "MED++", nullptr));
        pushButton->setText(QString());
        Ajouter->setText(QString());
        imprimer->setText(QCoreApplication::translate("Consultations", "Imprimer", nullptr));
        sauvegarder->setText(QCoreApplication::translate("Consultations", "sauvegarder", nullptr));
        label_4->setText(QCoreApplication::translate("Consultations", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600; color:#7777ff;\">NOTE:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Consultations", "<html><head/><body><p align=\"center\"><span style=\" font-size:xx-large; font-weight:600; font-style:italic; color:#5500ff;\">Espace Consultations</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Consultations", "Ajouter consultation", nullptr));
        pushButton_3->setText(QString());
        modifier_consultation->setText(QString());
        lc1->setText(QCoreApplication::translate("Consultations", "<html><head/><body><p align=\"center\"><span style=\" font-size:xx-large; font-weight:600; font-style:italic; color:#5500ff;\">Espace Consultations</span></p></body></html>", nullptr));
        choisir->setText(QString());
        actualiser->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Consultations", "Modifier consultation", nullptr));
        pushButton_5->setText(QString());
        supprimer_consultation->setText(QString());
        lc_2->setText(QCoreApplication::translate("Consultations", "<html><head/><body><p align=\"center\"><span style=\" font-size:xx-large; font-weight:600; font-style:italic; color:#5500ff;\">Espace Consultations</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Consultations", "Supprimer consultation", nullptr));
        pushButton_7->setText(QString());
        label_2->setText(QCoreApplication::translate("Consultations", "Trier Par : ", nullptr));
        tri_date->setText(QCoreApplication::translate("Consultations", "Date", nullptr));
        tri_reff->setText(QCoreApplication::translate("Consultations", "r\303\251f\303\251rence", nullptr));
        tri_id->setText(QCoreApplication::translate("Consultations", "identifiant", nullptr));
        lc_3->setText(QCoreApplication::translate("Consultations", "<html><head/><body><p align=\"center\"><span style=\" font-size:xx-large; font-weight:600; font-style:italic; color:#5500ff;\">Espace Consultations</span></p></body></html>", nullptr));
        rechercher->setText(QCoreApplication::translate("Consultations", "rechercher", nullptr));
        reff_consultation->setText(QString());
        label->setText(QCoreApplication::translate("Consultations", "Reff_consultation :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Consultations", "Afficher consultation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Consultations: public Ui_Consultations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTATIONS_H
