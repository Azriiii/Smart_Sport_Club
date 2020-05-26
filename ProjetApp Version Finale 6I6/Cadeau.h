
#ifndef CADEAU_H
#define CADEAU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Cadeau
{public:
    Cadeau();
    Cadeau (int,QString,QString);
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
   bool supprimer(int);
   QSqlQueryModel * chercher_Cadeau(int);
    QSqlQueryModel * chercher_Cadeau2(QString) ;
   QSqlQueryModel * sortid();
private:
    int id;
    QString jours;
    QString repas;
    QString dessert ;
    QString daate ;


    int note ;

};
#endif // Cadeau_H
