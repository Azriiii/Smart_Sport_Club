#ifndef CRUD_JOUEUR_H
#define CRUD_JOUEUR_H
#include "joueurs.h"
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class crud_joueur;
}

class crud_joueur : public QDialog
{
    Q_OBJECT

public:
    explicit crud_joueur(QWidget *parent = nullptr);
    ~crud_joueur();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_20_clicked();
    void con_pushButton_20_clicked();
    void on_pushButton_18_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_19_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

private:
    Ui::crud_joueur *ui;
    joueurs tmpjoueur;
};

#endif // CRUD_JOUEUR_H
