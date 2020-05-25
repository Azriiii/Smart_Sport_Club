#ifndef AbonnementWINDOW_H
#define AbonnementWINDOW_H

#include <QMainWindow>
#include <note_Cadeau.h>
namespace Ui {
class Abonnementwindow;
}

class Abonnementwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Abonnementwindow(QWidget *parent = nullptr);
    ~Abonnementwindow();

private slots:
    void on_pushButton_infpers_clicked();

    void on_pushButton_Cadeau_clicked();

    void on_pushButton_afficherCadeau_clicked();

    void on_pushButton_notezCadeau_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_ush_clicked();

private:
    Ui::Abonnementwindow *ui;
    note_Cadeau tmpnote ;
};

#endif // AbonnementWINDOW_H
