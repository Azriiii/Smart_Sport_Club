#include "fonctionnalite.h"
#include "ui_fonctionnalite.h"
#include "first.h"

fonctionnalite::fonctionnalite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fonctionnalite)
{
    ui->setupUi(this);
}

fonctionnalite::~fonctionnalite()
{
    delete ui;
}

void fonctionnalite::on_pushButton_clicked()
{
    hide();
   // mDialog = new crud_materiel(this); // allocated space for a new MyDialog
   first c;

   c.exec();
}
