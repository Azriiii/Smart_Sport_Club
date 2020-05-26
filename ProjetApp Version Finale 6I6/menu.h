#ifndef MENU_H
#define MENU_H

#include <QDialog>
//#include "Produit.h"
#include "Rafik.h"
#include "bienvenu.h"

#include "mainwindow.h"
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

  //  void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

    void on_Utilisateurs_Tournois_clicked();

private:
    Ui::menu *ui;
   // Smart * mDia;
    gestion * mD;
    bienvenu * m;
};

#endif // MENU_H
