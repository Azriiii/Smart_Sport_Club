#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "crud_actualite.h"
#include "crud_joueur.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gestion; }
QT_END_NAMESPACE

class gestion : public QMainWindow
{
    Q_OBJECT

public:
    gestion(QWidget *parent = nullptr);
    ~gestion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gestion *ui;
    crud_joueur *mDialog;
    crud_actualite *mDialo;
};
#endif // MAINWINDOW_H
