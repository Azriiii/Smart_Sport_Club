#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud_joueur.h"
#include "connexion.h"
#include "menu.h"
#include <QApplication>
#include "crud_actualite.h"


gestion::gestion(QWidget *parent )
    : QMainWindow(parent) ,
    ui(new Ui::gestion)


{

    ui->setupUi(this);


   }


gestion::~gestion()
{
    delete ui;
}


void gestion::on_pushButton_clicked()
{

    hide();
    mDialog = new crud_joueur(this); // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the gestion class
    mDialog->show();

}

void gestion::on_pushButton_2_clicked()
{
    hide();
    mDialo = new crud_actualite(this); // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the gestion class
    mDialo->show();
}

void gestion::on_pushButton_3_clicked()
{
    hide();
    menu c;
    c.exec();
}
