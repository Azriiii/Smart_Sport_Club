#ifndef ABONNE_H
#define ABONNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "Abonnement.h"

class Abonne : public Abonnement
{public:
    Abonne();
    Abonne(QString,float);
    QString get_typeabonnement();
    float get_presence();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString typeabonnement;
    float presence;
};
#endif // Abonne_H
