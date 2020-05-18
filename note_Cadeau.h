#ifndef NOTE_Cadeau_H
#define NOTE_Cadeau_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "Cadeau.h"
#include "Cadeauwindow.h"

class note_Cadeau
{
public:
    note_Cadeau();
    note_Cadeau(QString , int);
   bool ajouter_note_Cadeau ();
   QSqlQueryModel * afficher_note_Cadeau () ;
  int calculer_note(QString) ;
private :
    int id ,note;
    QString jours ;
};

#endif // NOTE_Cadeau_H
