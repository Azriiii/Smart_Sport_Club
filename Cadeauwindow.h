#ifndef CadeauWINDOW_H
#define CadeauWINDOW_H

#include <QMainWindow>
#include "Cadeau.h"



namespace Ui {
class CadeauWindow;
}

class CadeauWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CadeauWindow(QWidget *parent = nullptr);
    ~CadeauWindow();

private slots:
    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_retour_clicked();

    void on_Retour_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_chercherCadeau_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_label_Cadeau_linkActivated(const QString &link);

    void on_pushButton_trierParId_clicked();

private:
    Ui::CadeauWindow *ui;
     Cadeau tmpCadeau;
     Cadeau *tmpCadeauu ;





};

#endif // CadeauWINDOW_H
