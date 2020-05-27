#ifndef Abonnement_H
#define Abonnement_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Abonnement
{public:
    Abonnement();
    Abonnement(int,QString,QString,QString);
    QString get_nom();

    int get_id();
    bool ajouter();
    bool modifier(int,QString);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * sortid();
    QSqlQueryModel * sortnom();
    QSqlQueryModel * chercher_Abonnement(int);
    int calculer_presence() ;

private:
    QString nom ,  type_abonnement , date_abo;
    int id;
};

#endif // Abonnement_H
