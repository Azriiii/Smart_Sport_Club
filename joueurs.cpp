#include "joueurs.h"
#include <QDebug>


joueurs::joueurs()
{
    id=0;
    nom="";
    prenom="";
    poste="";
    num=0;

}


joueurs::joueurs(int id,QString nom, QString prenom, QString poste, int num)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->poste=poste;
    this->num=num;

}
QString joueurs::get_nom(){return nom;}
QString joueurs::get_prenom(){return prenom;}
QString joueurs::get_poste(){return poste;}
int joueurs::get_id(){return id;}
int joueurs::get_num(){return num;}

bool joueurs::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(num);
query.prepare("INSERT INTO joueurs (id, nom, prenom, poste, num) "
                    "VALUES (:id, :nom, :prenom, :poste, :num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":poste", poste);
query.bindValue(":num", res1);


return    query.exec();
}



QSqlQueryModel * joueurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from joueurs order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
    return model;
}
bool joueurs::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
if (id==0)
{
    return false;
}
else
{
    query.prepare("Delete from joueur where ref = :ref ");
    query.bindValue(":ref", res);
    return    query.exec();
}

}
/*QSqlQueryModel * joueurs::afficher3(int id,QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
    QString cherche="Select * from joueur where id like '"+res+"%' or nom like '"+nom+"%'";
if (id==0)
{
    model->setQuery("select * from joueur order by id");

}
else
{
    model->setQuery(cherche);

}
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));


    return model;
}*/

bool joueurs::modifier(int id,QString nom,QString prenom,QString poste,int num)
{

        QSqlQuery query;
        QString res= QString::number(id);
        QString res1= QString::number(num);
        query.prepare("UPDATE joueurs SET nom=:nom, prenom=:prenom, poste=:poste, num=:num WHERE id ='"+res+"' ");

        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":poste", poste);
        query.bindValue(":num", num);
         return    query.exec();
}

/*QSqlQueryModel * joueurs::afficher2(int id,QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
    QString cherche="Select * from joueur where id like '"+res+"%' or nom like '"+nom+"%'";
if (id==0)
{
    model->setQuery("select * from joueur order by id");

}
else
{
    model->setQuery(cherche);

}
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));


    return model;
}*/

/*QSqlQueryModel * joueurs::affichernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select nom from joueur");
    return model;
}
*/
QSqlQueryModel * joueurs::afficher2(QString id)
{QSqlQueryModel * model= new QSqlQueryModel();
    //QString res= QString::number(id);
    QString cherche="Select * from joueurs where id like '"+id+"%' or nom like '"+id+"%'";
if (id=="")
{
    model->setQuery("select * from joueurs order by id");

}
else
{
    model->setQuery(cherche);

}
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numéro"));

    return model;
}

QSqlQueryModel * joueurs::affichernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select nom from joueurs");
    return model;
}
QSqlQueryModel * joueurs::affichernomtrie(QString trie)
{QSqlQueryModel * model= new QSqlQueryModel();
    if(trie=="ID")
    {
        model->setQuery("select * from materiel order by id");

    }
    else if (trie=="Nom")
    {
        model->setQuery("select * from materiel order by nom");

    }
    else if (trie=="Prenom")
    {
        model->setQuery("select * from materiel order by prenom");

    }
    else if (trie=="Poste")
    {
        model->setQuery("select * from materiel order by poste");

    } else if (trie=="Numéro")
    {
        model->setQuery("select * from materiel order by num");

    }
    else
    {
        model->setQuery("select * from joueurs");
    }
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numéro"));
    return model;
}
