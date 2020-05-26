#ifndef TOURNOIS_H
#define TOURNOIS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Tournois
{
private:
    int ID ;
    QDate Date ;
    int Nombre_Equipe ;
    QString Adresse ;

public:
    Tournois();
    Tournois(int,QDate,int,QString);

    int get_ID ();
    QDate get_Date();
    int get_NombreEquipe();
    QString get_Adresse();

    bool Ajouter_Tournois();
    bool Modifier_Tournois();
    QSqlQueryModel * Afficher_Tournois () ;
    bool Supprimer_Torunois();
    QSqlQueryModel * Tri_Tournois_ID () ;
    QSqlQueryModel * Tri_Tournois_Date () ;
    QSqlQueryModel * Tri_Tournois_Equipe () ;



};

#endif // TOURNOIS_H
