#ifndef DONCONTROLLER_H
#define DONCONTROLLER_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class match
{
public:
    match();
    match(int,QString,int,int,QDate);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int idmatch;
    QString lieu;
    int id_equipe1,id_equipe2;
    QDate datee;
};

#endif // DONCONTROLLER_H
