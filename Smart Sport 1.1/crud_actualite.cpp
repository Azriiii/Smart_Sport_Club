#include "crud_actualite.h"
#include "ui_crud_actualite.h"
#include "actualite.h"
#include "QMessageBox"
#include<QDebug>
#include<QSqlError>
#include <QDialog>
#include "menu.h"
#include <QPainter>
#include <QPdfWriter>
#include "Accueil.h"




crud_actualite::crud_actualite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud_actualite)
{
    ui->setupUi(this);
    ui->tabactualite->setModel(tmpactualite.afficher());

}

crud_actualite::~crud_actualite()
{
    delete ui;
}

void crud_actualite::on_pushButton_3_clicked()
{   crud_actualite w;
    int ref = ui->ref->text().toInt();
    QString titre= ui->titre->text();
    QString description= ui->description->text();
    actualite e(ref,titre,description);
     bool test=e.ajouter();
    if(test)
    {
        ui->tabactualite->setModel(tmpactualite.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une actualite"),
        QObject::tr("actualité ajoutée"), QMessageBox::Ok);


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une actualité"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);
    w.show();

}
void crud_actualite::on_pushButton_11_clicked()
{   crud_actualite w;
    int reff = ui->ref->text().toInt();
    QString description=ui->description->text();
    QString titre=ui->titre->text();
    if (reff==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner une actualite"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
         QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
         msgBox.setText("Voullez-vous vraiment supprimer "+titre+" de la liste ?");
         msgBox.exec();

         if (msgBox.clickedButton() == connectButton)
         {
             msgBox.close();
             tmpactualite.supprimer(reff);
             ui->tabactualite->setModel(tmpactualite.afficher());
                 QMessageBox::information(nullptr, QObject::tr("Supprimer une actualité"),
                             QObject::tr("Actualité supprimée"), QMessageBox::Ok);
                   w.show();
             /*msgBox.close();

                 QMessageBox::information(nullptr, QObject::tr("Supprimer une actualite"),
                             QObject::tr("Actualite supprimée"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
         w.show();*/
    }

}}

void crud_actualite::on_pushButton_10_clicked()
{   crud_actualite w;
        int ref=ui->ref->text().toInt();
        QSqlQuery qry;
        QString titre=ui->titre->text();

        QString description=ui->description->text();
        if (titre=="" || ref ==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner une actualité"), QMessageBox::Ok);
        }
        else
        {
          /*  modification d;
            d.settitre(titre);
            d.setref(ref);
            d.setdescription(description);
            d.exec(); */
            ui->ref->setText(qry.value(0).toString());
            ui->titre->setText(qry.value(1).toString());
            ui->description->setText(qry.value(2).toString());
           bool test=tmpactualite.modifier(ref,titre,description);
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier actualité"),
                            QObject::tr("Actualité modifié"), QMessageBox::Ok);

            }
        }     w.show();

        ui->tabactualite->setModel(tmpactualite.afficher());
}
/*QSqlQueryModel * actualite::affichertitre()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select titre from actualite");
    return model;
}*/

void crud_actualite::on_pushButton_clicked()
{
    QSqlQuery query;
        QString id= ui->lineEdit->text();
        id=id+"%";
        qDebug()<<id;
        query.prepare("SELECT * from actualite where(id LIKE :id)");
        query.bindValue(":id",id);
        if(!query.exec())
        {
            //qDebug()<<query.lastError();
        }
        QSqlQueryModel * modal= new QSqlQueryModel();
        modal->setQuery(query);
        qDebug()<<modal->rowCount();
        ui->tabactualite->setModel(modal);
}

void crud_actualite::on_pushButton_2_clicked()
{
    menu w;
    hide();
    w.exec();
}

void crud_actualite::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:/Users/fares/Desktop/actualite.pdf");
             QPainter painter(&pdf);
            int i = 4000;
                 painter.setPen(Qt::blue);
                 painter.setFont(QFont("Arial", 30));
                 painter.drawText(1100,1200,"Liste Des Actualités");
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Arial", 15));
                // painter.drawText(1100,2000,afficheDC);
                 painter.drawRect(100,100,7300,2600);
                 //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                 painter.drawRect(0,3000,9600,500);
                 painter.setFont(QFont("Arial", 9));
                 painter.drawText(200,3300,"Reference");
                 painter.drawText(1300,3300,"Titre");
                 painter.drawText(2100,3300,"Description");

                 QSqlQuery query;
                 query.prepare("select * from actualite");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(200,i,query.value(0).toString());
                     painter.drawText(1300,i,query.value(1).toString());
                     painter.drawText(2200,i,query.value(2).toString());

                    i = i + 500;
                 }
                 int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                          painter.end();
                     }
}

void crud_actualite::on_pushButton_5_clicked()
{
   /* Accueil a ;
    hide();
    a.exec();*/
}

