#include "equipe.h"

equipe::equipe()
{

}

equipe::equipe(int id, QString nom, QString division, int id_match,QString type)
{
    this->id=id;
    this->nom=nom;
    this->division=division;
    this->id_match=id_match;
    this->type=type;
}

bool equipe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPE (ID, NOM, DIVISION,ID_MATCH,TYPE) "
                        "VALUES (:id, :nom, :division,:id_match,:type)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":division", division);
    query.bindValue(":id_match", id_match);
    query.bindValue(":type", type);
    return    query.exec();
}

QSqlQueryModel *equipe::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,NOM,DIVISION,ID_MATCH,TYPE from EQUIPE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DIVISION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID MATCH"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

bool equipe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EQUIPE SET NOM=:nom, DIVISION=:division, ID_MATCH=:id_match , TYPE=:type "
                        "WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":division", division);
    query.bindValue(":id_match", id_match);
    query.bindValue(":type", type);
    return    query.exec();
}

bool equipe::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE "
                        "WHERE ID=:id");
    query.bindValue(":id", id);

    return    query.exec();
}

QSqlQueryModel *equipe::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,NOM,DIVISION,ID_MATCH,TYPE from EQUIPE "+cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DIVISION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID MATCH"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel *equipe::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from EQUIPE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
