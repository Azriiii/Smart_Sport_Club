#ifndef EQUIPE_CONTROLLER_H
#define EQUIPE_CONTROLLER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class equipe
{
public:
    equipe();
    equipe(int id, QString nom,QString division,int id_match,QString type);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int id,id_match;
    QString nom,division,type;

};

#endif // EQUIPE_CONTROLLER_H
