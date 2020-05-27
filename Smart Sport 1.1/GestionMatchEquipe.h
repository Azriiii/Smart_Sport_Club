#ifndef GESTIONMATCHEQUIPE_H
#define GESTIONMATCHEQUIPE_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class GestionMatchEquipe; }
QT_END_NAMESPACE

class GestionMatchEquipe : public QDialog
{
    Q_OBJECT

public:
    GestionMatchEquipe(QWidget *parent = nullptr);
    ~GestionMatchEquipe();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_supprimer_4_clicked();

    void on_data_clicked(const QModelIndex &index);

    void on_lineEdit_id_6_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_supprimer_6_clicked();

    void on_lineEdit_id_7_textChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_data_2_clicked(const QModelIndex &index);

    void on_id_tri_currentTextChanged(const QString &arg1);

    void on_id_tri2_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton24_clicked();

    void on_pushButton24_2_clicked();


    void on_pushButton_33_clicked();

private:
    Ui::GestionMatchEquipe *ui;

};
#endif // RAFIK_H
