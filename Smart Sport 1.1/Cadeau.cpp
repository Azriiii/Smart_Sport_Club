#include "Cadeau.h"
#include "connexion.h"

#include <QDebug>
Cadeau::Cadeau()
{
id=0;
jours="";

note=0;
}
Cadeau::Cadeau(int id,QString jours,QString daate)
{
  this->id=id;
  this->jours=jours;

   this->daate=daate ;
 // this->note= note ;
}


bool Cadeau::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Cadeau (ID, JOURS, DAATE) "
                    "VALUES (:id, :jours, :daate)");
query.bindValue(":id", res);
query.bindValue(":jours", jours);

query.bindValue(":daate", daate);
//query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel * Cadeau::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Cadeau");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Jours "));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("daate "));
//model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
    return model;
}

bool Cadeau::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Cadeau where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel *Cadeau::chercher_Cadeau(int id)
{
QSqlQueryModel *model= new QSqlQueryModel();
QString str ;
//Connexion Conn;
//Conn.ouvrirConnexion();
//Conn.openBD();
if(id== NULL){
    str="SELECT * FROM  Cadeau";
}

     str="select * from Cadeau where ID ="+QString::number(id);
    model->setQuery(str);
//Conn.fermerConnexion() ;
    return model;
}

QSqlQueryModel *Cadeau ::chercher_Cadeau2 (QString jours)
{
    QSqlQueryModel *model= new QSqlQueryModel();
     QString str="select * from Cadeau where jours ='"+jours+"'";
     model->setQuery(str);
     return model;
}

QSqlQueryModel *Cadeau::sortid()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from Cadeau ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("jours"));

    model->setHeaderData(4,Qt::Horizontal,QObject::tr("daate"));

    return model;
}



