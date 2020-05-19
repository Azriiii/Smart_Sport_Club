#include "actualite.h"
#include <QDebug>


actualite::actualite()
{
    ref=0;
    description="";
    titre="";
}
actualite::actualite(int ref,QString description, QString titre)
{
    this->ref=ref;
    this->titre=titre;
    this->description=description;
}
int actualite::get_ref(){return ref;}
QString actualite::get_titre(){return titre;}
QString actualite::get_description(){return description;}


bool actualite::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);
query.prepare("INSERT INTO actualite (id, titre, description) "
                    "VALUES (:id, :titre, :description)");
query.bindValue(":id", res);
query.bindValue(":titre", titre);
query.bindValue(":description", description);

return    query.exec();
}

QSqlQueryModel * actualite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from actualite order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    return model;
}


bool actualite::supprimer(int )
{
QSqlQuery query;
QString res= QString::number(ref);
if (ref==0)
{
    return false;
}
else
{
    query.prepare("delete from actualite where id = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

}
bool actualite::modifier(int ref,QString titre,QString description)
{

        QSqlQuery query;
        QString res= QString::number(ref);
        query.prepare("UPDATE actualite SET titre=:titre, description=:description WHERE id ='"+res+"' ");

       // query.bindValue(":id", res);
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
         return    query.exec();
}


