#include "Abonnementwindow.h"
#include "ui_Abonnementwindow.h"
#include "Abonnement.h"
#include "Cadeauwindow.h"
#include "Cadeau.h"
#include "note_Cadeau.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "Abonnement.h"
#include "bienvenu.h"
#include "ui_bienvenu.h"
#include <QDesktopServices>
#include "QSqlQuery"
#include <qsystemtrayicon.h>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QUrl>

#include <QDebug>
Abonnementwindow::Abonnementwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Abonnementwindow)
{
    ui->setupUi(this);
}

Abonnementwindow::~Abonnementwindow()
{
    delete ui;
}

void Abonnementwindow::on_pushButton_infpers_clicked()
{

}

void Abonnementwindow::on_pushButton_Cadeau_clicked()
{

}

void Abonnementwindow::on_pushButton_afficherCadeau_clicked()
{
    QString daate;
      Cadeau *tmpCadeauu ;
     QSqlQueryModel *model ;
     daate = ui->lineEdit_inserezCadeau->text() ;
      model =tmpCadeauu->chercher_Cadeau2 (daate);
      ui->tableView_Cadeau2->show() ;
      ui->tableView_Cadeau2->setModel(model);
}

void Abonnementwindow::on_pushButton_notezCadeau_clicked()
{
    QSqlQuery qrt;
     QString jours;
     bool test;
     int note ;
     MainWindow w ;
     jours = ui->lineEdit_inserezCadeau->text() ;
     note = ui->spinBox_note->text().toInt() ;
     note_Cadeau nm(jours,note) ;
      test=nm.ajouter_note_Cadeau();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Noter Cadeau"),
                      QObject::tr(" note  effectué , merci .\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Noter Cadeau"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}



/*void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString type_pension=ui->type_pension->currentText() ;
    QString date_abo = ui->dateEdit->text();



  Abonnement e(id,nom,prenom,type_pension,date_abo);
  bool test=e.ajouter();
  if(test)
{ui->tabAbonnement->setModel(tmpAbonnement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Abonnement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}*/


/*bool reclamation_de_production::ajouter_reclamation_de_production()
{QSqlQuery qrt;



    QString format = "dd.MM.yyyy";
    QString ch= date_reclamation.toString(format);



if(Numero_recl==NULL){

    QString str="INSERT INTO Reclamation_production VALUES(null,'"+ch+"','"+Description+"','"+Sujet+"','"+Destination+"')";

    bool resultat=qrt.exec(str);

     return resultat;
}else{
    QString str="UPDATE Reclamation_production SET date_reclamation='"+ch+"',Description='"+Description+"',Sujet='"+Sujet+"',Destination='"+Destination+"' where Numero_recl="+QString::number(Numero_recl);

    bool resultat=qrt.exec(str);
     return resultat;
}
}
*/

void Abonnementwindow::on_pushButton_clicked()
{
    int id ;
     QSqlQueryModel *model ;
     Abonnement *et ;
     id = ui->lineEdit->text().toInt() ;
      model =et->chercher_Abonnement (id);
      ui->tableAbonnement->show() ;
      ui->tableAbonnement->setModel(model);

}






void Abonnementwindow::on_pushButton_2_clicked()
{
    bienvenu  *b=   new bienvenu();
    this->close() ;
    b->show() ;
}
void Abonnementwindow::on_ush_clicked()
{
   QDesktopServices::openUrl(QUrl("http://www.google.fr"));
}
