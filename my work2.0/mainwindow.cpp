#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Abonnement.h"
#include "bienvenu.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "Abonnement.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabAbonnement->setModel(tmpAbonnement.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();

    QString type_pension=ui->type_pension->currentText() ;
    QString date_abo = ui->dateEdit->text();



  Abonnement e(id,nom,type_pension,date_abo);
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


}

void MainWindow::on_pb_supprimer_clicked()
{
/*QString nom= ui->lineEdit_id->text() ;
Abonnement *e= new Abonnement() ;

bool test=e->supprimer(nom);
if(test)

{ui->tabAbonnement->setModel(s->afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),

                             QObject::tr("Abonnement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);*/


//**********************
int id = ui->lineEdit->text().toInt();
 bool test=tmpAbonnement.supprimer(id);
 if(test)
 {ui->tabAbonnement->setModel(tmpAbonnement.afficher());//refresh
     QMessageBox::information(nullptr, QObject::tr("Supprimer un abonné"),
                 QObject::tr("Abonné supprimé.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonné"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_Retour_clicked()
{
    bienvenu  *b=   new bienvenu();
    this->close() ;
    b->show() ;

}

void MainWindow::on_modifier_etu_clicked()
{

/*    QString nom,prenom;
    int id;
    id=ui->lineEdit_id_2->text().toInt();
    nom=ui->lineEdit_nom_2->text();
    prenom=ui->lineEdit_prenom_2->text();
    // m = a.toInt();
     if (ui->lineEdit_id_2->text().isEmpty())
     {

         QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

     }
   else   if (ui->lineEdit_nom_2->text().isEmpty())
     {

         QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP nom  !!!!") ;

     }
 else    if (ui->lineEdit_prenom_2->text().isEmpty())
     {

         QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
     }

else
     {
     QSqlQuery qry ;
  qry.prepare("update Abonnement set id='"+QString::number(id)+"', nom='"+nom+"', prenom='"+prenom+"' where id="+QString::number(id));

  if (qry.exec())
  {
      QMessageBox::critical(this,tr("modifier"),tr("modification effectué"));

  }
    }*/

   //*********************
     QString nom,prenom;
     int id;
     id=ui->lineEdit_id_2->text().toInt();
     nom=ui->lineEdit_nom_2->text();

     if (ui->lineEdit_id_2->text().isEmpty())
     {

         QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

     }
   else   if (ui->lineEdit_nom_2->text().isEmpty())
     {

         QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP nom  !!!!") ;

     }

else{
     //int id = ui->lineEdit->text().toInt();
      bool test=tmpAbonnement.modifier(id,nom);
      if(test)
      {ui->tabAbonnement->setModel(tmpAbonnement.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Modifier un abonné"),
                      QObject::tr("Abonné modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un abonné"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
     }
}





//***********
/*void dia_modif_emp::on_pb_ajouter_emp_clicked()
{
    QString a,b,c,d,e,f,g,h,i,j,k,kk;
        int m,m2,m3;

       // a=ui->lineEdit_cin->text();
       // m=a.toInt();

        b=ui->lineEdit_nom->text();
        c=ui->lineEdit_prenom->text();

        d=ui->comboBox_sexe->itemText(0);


        e=ui->lineEdit_nation->text();
        f=ui->lineEdit_num_de_tel->text();
        g=ui->lineEdit_salaire->text();

        h=ui->dateEdit->text();
        j=ui->comboBox_poste->itemText(5);
        k=ui->lineEdit_email->text();
        kk="";

       QDate converted_date(QDate::fromString(h, "dd/MM/yyyy"));

        ///d=dd.fromString(&e,Qt::DateFormat("YYYY-MM-DD"));
        m = a.toInt();
        m2=g.toInt();
        m3=f.toInt();

        QMessageBox msgBox;
            emp=new Employe(cin_mod,b,c,d,e,converted_date,m3,k,j,m2);

           if(emp->modifier_empl(cin_mod))
                   {
               msgBox.setText("UPDATE Done");
               msgBox.exec();
         // QMessageBox::Information()
                    }
}*/

void MainWindow::on_pushButton_trier_id_clicked()
{

    ui->tabAbonnement->setModel(tmpAbonnement.sortid());

}



void MainWindow::on_pushButton_2_clicked()
{
    ui->tabAbonnement->setModel(tmpAbonnement.sortnom());
}





/*void MainWindow::on_pushButton_3_clicked()
{
    ui->table_note->setModel(tmpmenu.afficher_note_menu());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                      QObject::tr("Abonnement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}*/



void MainWindow::on_pushButton_calculernbrepresence_clicked()
{
   // QString daate ;
       // note_menu tmpmenu ;
        //daate=ui->lineEdit->text() ;
    Abonnement e ;
        int nbre_presence;
        nbre_presence = e.calculer_presence();

      ui->label_presence->setText(QString::number(nbre_presence)) ;
}
