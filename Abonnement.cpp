#include "Abonnement.h"
#include <QDebug>
#include "QSqlQuery"
#include <QString>
#include <QSqlQueryModel>
Abonnement::Abonnement()
{
//id=0;
nom="";

}
Abonnement::Abonnement(int id,QString nom, QString type_abonnement,QString date_abo)
{
  this->id=id;
 this->nom=nom;

  this->type_abonnement = type_abonnement ;
  this->date_abo = date_abo ;
}
QString Abonnement::get_nom(){return  nom;}

int Abonnement::get_id(){return  id;}

bool Abonnement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Abonnement (ID, NOM,TYPE_abonnement,DATE_ABO) "
                    "VALUES (:id, :nom,  :type_abonnement, :date_abo)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);

query.bindValue(":type_abonnement", type_abonnement);
query.bindValue(":date_abo", date_abo);

return    query.exec();
}

QSqlQueryModel * Abonnement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
 QString str="SELECT *FROM  Abonnement";
model->setQuery(str);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));

model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_abonnement "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_abo"));

    return model;
}


/*bool Abonnement ::supprimer (int idd)
{QSqlQuery qrt;
    QString str="delete from Abonnement where ID= "+QString::number(idd);
    qDebug()<<str;
    bool res = qrt.exec(str);
    return res;

//return(qrt.exec(str));
}*/



bool Abonnement ::supprimer (int id)
{/*QSqlQuery qry;
    //qry.prepare("Delete from Abonnement where id= "+QString::number(id));
qry.prepare("Delete from Abonnement where nom='"+nom+"'");
    bool res = qry.exec();
    return res;*/

    //****
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from Abonnement where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();

//return(qrt.exec(str));
}

bool Abonnement :: modifier( int id , QString nom )
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update Abonnement set ID='"+QString::number(id)+"', nom='"+nom+"'where id="+QString::number(id));
    query.bindValue(":id", res);
    return    query.exec();


}


QSqlQueryModel *Abonnement ::sortid()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from Abonnement ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));


    return model;
}


QSqlQueryModel *Abonnement ::sortnom()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from Abonnement ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));


    return model;
}


QSqlQueryModel *Abonnement::chercher_Abonnement(int id)
{
QSqlQueryModel *model= new QSqlQueryModel();
QString str ;
//Connexion Conn;
//Conn.ouvrirConnexion();
//Conn.openBD();

    str="select * from Abonnement where ID ="+QString::number(id);
   model->setQuery(str);
//Conn.fermerConnexion() ;
   return model;
}
int Abonnement::calculer_presence()
{

    QSqlQuery qry;
    qry.prepare("select * from Abonnement" );


    int i =0 ;
    if(qry.exec())
     {

        while (qry.next())
          {

             i++ ;
          }

}

    return i ;

}








