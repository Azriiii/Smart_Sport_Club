#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");
db.setUserName("Roua");//inserer nom de l'utilisateur
db.setPassword("roua1997");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
