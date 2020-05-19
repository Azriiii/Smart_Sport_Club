#include "tournois.h"
#include <QDate>
Tournois::Tournois()
{


}


Tournois::Tournois(int id, QDate date,int nombre_equipe, QString adresse)
{
    this->ID=id;
    this->Date=date;
    this->Nombre_Equipe=nombre_equipe;
    this->Adresse=adresse;
}


int Tournois::get_ID(){return ID;}
QDate Tournois::get_Date(){return Date;}
int Tournois::get_NombreEquipe(){return Nombre_Equipe;}
QString Tournois::get_Adresse(){return Adresse;}


bool Tournois::Ajouter_Tournois()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO TOURNOIS (ID, DATET, NBEQUIPE, ADRESSE) "
                    "VALUES (:Id, :Date, :NbEquipe, :Adresse)");
query.bindValue(":Id", res);
query.bindValue(":Date",Date );
query.bindValue(":NbEquipe",Nombre_Equipe );
query.bindValue(":Adresse", Adresse);

return    query.exec();
}

bool Tournois::Supprimer_Torunois()
{
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("DELETE from TOURNOIS where ID=:Id");
    query.bindValue(":Id", res);
    return    query.exec();
}

bool Tournois::Modifier_Tournois()
{
    QSqlQuery query ;
    QString res=QString::number(ID);
    query.prepare("Update Tournois set DATET=:date, NBEQUIPE=:nbequipe, ADRESSE=:adresse where ID=:id ");
            query.bindValue(":id",res);
            query.bindValue(":date", Date );
            query.bindValue(":nbequipe",Nombre_Equipe);
            query.bindValue(":adresse", Adresse);
            return query.exec();
}


QSqlQueryModel * Tournois::Afficher_Tournois()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Tournois");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre d'equipe"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    return model;
}

QSqlQueryModel*  Tournois::Tri_Tournois_ID()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *r = new QSqlQuery();
     r->prepare("SELECT * FROM Tournois ORDER BY ID ASC");
     r->exec();
     model->setQuery(*r);
     return model ;

}

QSqlQueryModel*  Tournois::Tri_Tournois_Date()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *r = new QSqlQuery();
     r->prepare("SELECT * FROM Tournois ORDER BY DATET ASC");
     r->exec();
     model->setQuery(*r);
     return model ;

}

QSqlQueryModel*  Tournois::Tri_Tournois_Equipe()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *r = new QSqlQuery();
     r->prepare("SELECT * FROM Tournois ORDER BY NBEQUIPE");
     r->exec();
     model->setQuery(*r);
     return model ;

}

