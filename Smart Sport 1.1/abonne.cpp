#include "abonne.h"


#include "Abonnement.h"
#include <QDebug>

Abonne::Abonne()
{
typeabonnement="";
presence=false;

}
Abonne::Abonne(QString typeabonnement,float presence)
{
  this->typeabonnement=typeabonnement;
  this->presence=presence;

}
QString Abonne::get_typeabonnement(){return  typeabonnement;}
float Abonne::get_presence(){return presence;}

/*
bool Abonne::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Abonnement (ID, NOM) "
                    "VALUES (:id, :nom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);


return    query.exec();
}

QSqlQueryModel * Abonnement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Abonnement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool Abonnement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Abonnement where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}



*/
