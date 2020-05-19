#include "cad.h"
#include <QString>
#include <QSqlQuery>
Cadeau::Cadeau()
{
num=0;
type="";
}
Cadeau::Cadeau(int num,QString type)
{
    this->num=num;
    this->type=type;
}
int Cadeau::get_num()
{
    return  num;
}
QString Cadeau::get_type()
{return type;}
bool Cadeau::Cadeau_ajouter()
{
    QSqlQuery query;
    QString res1 = QString::number(num);

    query.prepare("INSERT INTO Cadeau (num, type) "
                        "VALUES (:num, :type)");
    query.bindValue(":num", res1);

    query.bindValue(":type", type);


    return    query.exec();
}
bool supprimer(int  num)
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("Delete from Cadeau where NUM=:num ");
    query.bindValue(":num",num);
    return    query.exec();
    }


QSqlQueryModel * Cadeau::afficherCadeau()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Cadeau");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("type "));

    return model;
}

bool Cadeau::supprimer(int x)
{
    QSqlQuery query;
    QString res=QString::number(x);
    query.prepare("Delete from Cadeau where NUM=:num");
    query.bindValue(":num", res);
    return query.exec();

}
bool Cadeau::modifier()
{
    QSqlQuery query;
    QString res=QString::number(num);
    query.prepare(" UPDATE Cadeau set TYPE = :type where NUM  = :num ");
    query.bindValue(":num", res);
    query.bindValue(":type",type);


    return query.exec();



}

