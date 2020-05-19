#include "crud_actualite.h"
#include "ui_crud_actualite.h"
#include "actualite.h"
#include "QMessageBox"
#include<QDebug>
#include<QSqlError>
#include <QDialog>



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
    int ref = ui->ref->text().toInt();
    QString description=ui->description->text();
    QString titre=ui->titre->text();
    if (ref==0)
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

                 QMessageBox::information(nullptr, QObject::tr("Supprimer une actualite"),
                             QObject::tr("Actualite supprimée"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
         w.show();
    }

}

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
            qDebug()<<query.lastError();
        }
        QSqlQueryModel * modal= new QSqlQueryModel();
        modal->setQuery(query);
        qDebug()<<modal->rowCount();
        ui->tabactualite->setModel(modal);
}
