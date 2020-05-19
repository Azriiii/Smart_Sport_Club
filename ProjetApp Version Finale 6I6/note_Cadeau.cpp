#include "note_Cadeau.h"
#include "Cadeau.h"
#include "connexion.h"
#include "QSqlQueryModel"
#include "QSqlQuery"


note_Cadeau::note_Cadeau()
{

}

note_Cadeau::note_Cadeau(QString jours , int note)
{
    this->jours=jours ;
    this->note=note ;
}

bool note_Cadeau::ajouter_note_Cadeau()
{
QSqlQuery query;
QString res= QString::number(note);
query.prepare("INSERT INTO note_Cadeau (JOURS, NOTE ) "
                    "VALUES (:jours, :note)");
//query.bindValue(":id", res);
query.bindValue(":jours", jours);
query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel *note_Cadeau::afficher_note_Cadeau()
{QSqlQueryModel * model= new QSqlQueryModel();
 QString str="SELECT *FROM  note_Cadeau";
model->setQuery(str);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("daate"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("note"));


    return model;
}

  int note_Cadeau ::calculer_note(QString jours)

  {
      QSqlQuery qry;
      qry.prepare("select * from note_Cadeau where daate='"+jours+"'" );
     int notetot=0 ;
      int note2 ;
      int i =0 ;
      if(qry.exec())
       {

          while (qry.next())
            {
              note2  = qry.value(1).toInt();
               notetot = notetot+ note2 ;
               i++ ;
            }

  }
      notetot = notetot/i ;
      return notetot ;
}
