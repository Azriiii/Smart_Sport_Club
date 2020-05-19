#ifndef UTILISATEURS_H
#define UTILISATEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Utilisateurs
{
private:
    int Cin ;
    QString Nom ;
    QString MotDePasse ;
    QString Adresse ;
    QString Role ;
public:
    Utilisateurs();
    Utilisateurs(int,QString,QString,QString,QString);

    int get_Cin ();
    QString get_Nom();
    QString get_MotDePasse();
    QString get_Adresse();
    QString get_Role();

    bool Ajouter_Utilisateur();
    bool Modifier_uitlisateur();
    QSqlQueryModel * Afficher_utilisateur () ;
    bool Supprimer_utilisateur();
    bool Login(int,QString);
    QSqlQueryModel * Tri_Utilisateur_Nom();
    QSqlQueryModel * Tri_Utilisateur_Role();
    QSqlQueryModel* Rechercher_Utilisateur(const QString &str);




};

#endif // UTILISATEURS_H
