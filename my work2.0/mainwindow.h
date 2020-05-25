#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Abonnement.h"
#include "note_Cadeau.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //int id2;

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabAbonnement_activated(const QModelIndex &index);

    void on_Retour_clicked();

    void on_modifier_etu_clicked();

    void on_pushButton_trier_id_clicked();

    void on_pushButton_2_clicked();

    void on_table_note_clicked(const QModelIndex &index);

    void on_table_note_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_calculernbrepresence_clicked();

private:
    Ui::MainWindow *ui;
    Abonnement tmpAbonnement;
    Abonnement *s;
    note_Cadeau tmpCadeau ;

};

#endif // MAINWINDOW_H
