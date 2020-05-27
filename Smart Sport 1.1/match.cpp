#include "match.h"

match::match()
{

}

match::match(int idmatch, QString lieu, int id_equipe1, int id_equipe2, QDate datee)
{
    this->idmatch=idmatch;
    this->lieu=lieu;
    this->id_equipe1=id_equipe1;
    this->id_equipe2=id_equipe2;

    this->datee=datee;
}

bool match::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO MATCH (IDMATCH, LIEU, ID_EQUIPE1,ID_EQUIPE2,DATEE) "
                            "VALUES (:idmatch, :lieu, :id_equipe1,:id_equipe2,:datee)");
        query.bindValue(":idmatch", idmatch);
        query.bindValue(":lieu", lieu);
        query.bindValue(":id_equipe1", id_equipe1);
        query.bindValue(":id_equipe2", id_equipe2);

        query.bindValue(":datee", datee);
        return    query.exec();
}

QSqlQueryModel *match::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MATCH");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID EQUIPE1"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID EQUIPE2"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

bool match::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE MATCH SET LIEU=:lieu, ID_EQUIPE1=:id_equipe1,ID_EQUIPE2=:id_equipe2,DATEE=:datee "
                        "WHERE IDMATCH=:idmatch");
    query.bindValue(":idmatch", idmatch);
    query.bindValue(":lieu", lieu);
    query.bindValue(":id_equipe1", id_equipe1);
    query.bindValue(":id_equipe2", id_equipe2);
    query.bindValue(":datee", datee);
    return    query.exec();
}

bool match::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM MATCH WHERE IDMATCH=:idmatch");
    query.bindValue(":idmatch", idmatch);
    return    query.exec();
}

QSqlQueryModel *match::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MATCH " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID EQUIPE1"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID EQUIPE2"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

QSqlQueryModel *match::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MATCH");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
