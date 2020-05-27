#include "fonct.h"
#include "ui_fonctionanalite.h"
#include  "first.h"

fonct::fonct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fonct)
{
    ui->setupUi(this);
}

fonct::~fonct()
{
    delete ui;
}

void fonct::on_pushButton_clicked()
{
    hide();
    first c;

    c.exec();
}
