#ifndef ACTUALITE_H
#define ACTUALITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class actualite
{
public:
    actualite();
    actualite(int,QString,QString);
    int get_ref();
    QString get_description();
    QString get_titre();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * afficher2(int,QString nom);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher3(int,QString);
private:
    QString description,titre;
    int ref;
};

#endif // ACTUALITE_H
