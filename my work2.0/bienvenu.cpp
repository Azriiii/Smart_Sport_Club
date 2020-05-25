#include "bienvenu.h"
#include "ui_bienvenu.h"
#include"mainwindow.h"
#include "Cadeau.h"
#include "Cadeauwindow.h"
#include "Abonnement.h"
#include "Abonnementwindow.h"
#include <QtWidgets>


bienvenu::bienvenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienvenu)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/roua/Pictures/lab.png");
    ui->label_pic->setPixmap(pix) ;

}

bienvenu::~bienvenu()
{
    delete ui;
}

void bienvenu::on_pushButton_2_clicked()
{

  MainWindow *w =new MainWindow();
  this->close() ;
  w->show();

}

void bienvenu::on_pushButton_clicked()
{
   CadeauWindow  *w= new CadeauWindow();
   this->close() ;
   w->show() ;
}

void bienvenu::on_pushButton_4_clicked()
{
    Abonnementwindow  *ew = new Abonnementwindow();
    this->close() ;
   ew->show() ;

}
