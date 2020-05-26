#include "Cadeauwindow.h"
#include "ui_Cadeauwindow.h"
#include <QMessageBox>
#include "Cadeau.h"
#include "bienvenu.h"
#include "connexion.h"
#include "QSqlQueryModel"
#include "QSqlQuery"
#include "note_Cadeau.h"


CadeauWindow::CadeauWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CadeauWindow)
{


    ui->setupUi(this);
    ui->tabCadeau->setModel(tmpCadeau.afficher());

    QPixmap pi("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/f1.jpg");
    ui->label_Cadeau->setPixmap(pi) ;
    QPixmap pi2("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/f3.jpg");
    ui->label_Cadeau2->setPixmap(pi2) ;

    QPixmap pix4("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/ff1.png");
    ui->label_fleche->setPixmap(pix4) ;


}

CadeauWindow::~CadeauWindow()
{
    delete ui;
}


void CadeauWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString jours= ui->lineEdit_jours->text();

    QString daate = ui->lineEdit_date->text();
   // int note = ui->lineEdit_note->text().toInt();
  Cadeau M (id,jours,daate);
  bool test=M.ajouter();
  if(test)
{ui->tabCadeau->setModel(tmpCadeau.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Cadeau"),
                  QObject::tr("Cadeau ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Cadeau"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void CadeauWindow::on_Retour_clicked()
{
    bienvenu  *b=   new bienvenu();
    this->close() ;
    b->show() ;

}

void CadeauWindow::on_pb_supprimer_clicked()
{
   /* //Connexion c ;
    int id = ui->lineEdit_id_2->text().toInt();
   // c.ouvrirConnexion() ;
    QSqlQuery qry ;
    qry.prepare("Delete from Cadeau where ID ="+QString::number(id)) ;
    if (qry.exec())
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Cadeau"),
                    QObject::tr("Cadeau supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       // c.fermerConnexion() ;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Cadeau"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }*/
   int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpCadeau.supprimer(id);
    if(test)
    {ui->tabCadeau->setModel(tmpCadeau.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Cadeau"),
                    QObject::tr("Cadeau supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Cadeau"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}



void CadeauWindow::on_pushButton_chercherCadeau_clicked()
{
    int id ;
     QSqlQueryModel *model ;
     id = ui->lineEdit_chercherCadeau->text().toInt() ;
      model =tmpCadeauu->chercher_Cadeau (id);
      ui->tabCadeau->show() ;
      ui->tabCadeau->setModel(model);



}

/*void ERP::on_pushButton_163_clicked()
{
    int num_commande =ui->LE_rech_comm ->text().toInt();
           QSqlQueryModel *model =tmp->chercher_commande(num_commande);
           int IDRech = model->data(model->index(0, 0)).toInt();

           if(num_commande == IDRech)
           {

               ui->tab_aff_commande_3->show();
                    ui->tab_aff_commande_3->setModel(model);



           }
}*/





void CadeauWindow::on_pushButton_5_clicked()
{
    note_Cadeau tmpCadeau ;
    ui->table_note->setModel(tmpCadeau.afficher_note_Cadeau());//refresh

}

void CadeauWindow::on_pushButton_4_clicked()
{ QString jours ;
    note_Cadeau tmpCadeau ;
    jours=ui->lineEdit->text() ;
    int somme ;
    somme =tmpCadeau.calculer_note(jours);

  ui->label_13->setText(QString::number(somme)) ;


}



void CadeauWindow::on_pushButton_trierParId_clicked()
{
     ui->tabCadeau->setModel( tmpCadeau.sortid());
}
