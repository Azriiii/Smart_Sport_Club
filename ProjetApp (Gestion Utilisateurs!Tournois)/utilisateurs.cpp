#include "utilisateurs.h"

Utilisateurs::Utilisateurs()
{
    Cin=0;
    Nom="";
    MotDePasse="";
    Adresse="";
    Role="";
}

Utilisateurs::Utilisateurs(int cin,QString nom,QString motdepasse,QString adresse,QString role)
{
    this->Cin=cin;
    this->Nom=nom;
    this->MotDePasse=motdepasse;
    this->Adresse=adresse;
    this->Role=role;
}

int Utilisateurs::get_Cin(){return Cin;}
QString Utilisateurs::get_Nom(){return Nom;}
QString Utilisateurs::get_MotDePasse(){return MotDePasse;}
QString Utilisateurs::get_Adresse(){return Adresse;}
QString Utilisateurs::get_Role(){return Role;}

bool Utilisateurs::Ajouter_Utilisateur()
{
QSqlQuery query;
QString res= QString::number(Cin);
query.prepare("INSERT INTO utilisateur (CIN, NOM, MOTDEPASSE, ADRESSE, ROLE) "
                    "VALUES (:Cin, :Nom, :Motdepasse, :Adresse, :Role)");
query.bindValue(":Cin", res);
query.bindValue(":Nom", Nom);
query.bindValue(":Motdepasse", MotDePasse );
query.bindValue(":Adresse", Adresse);
query.bindValue(":Role", Role);

return    query.exec();
}

QSqlQueryModel * Utilisateurs::Afficher_utilisateur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Utilisateur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MOTDEPASSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));
    return model;
}

bool Utilisateurs::Supprimer_utilisateur()
{
QSqlQuery query;
QString res= QString::number(Cin);
query.prepare("DELETE FROM Utilisateur WHERE CIN = :Cin ");
query.bindValue(":Cin", res);
return    query.exec();
}


bool Utilisateurs::Modifier_uitlisateur()
{
    QSqlQuery query ;
    QString res=QString::number(Cin);
    query.prepare("Update Utilisateur set MOTDEPASSE=:Motdepasse, ADRESSE=:Adresse,ROLE=:Role where CIN=:Cin ");
            query.bindValue(":Cin",res);
            query.bindValue(":Motdepasse", MotDePasse );
            query.bindValue(":Adresse", Adresse);
            query.bindValue(":Role", Role);
            return query.exec();
}

bool Utilisateurs::Login(int Cin,QString Motdepasse)
{
    int i=0;
    QSqlQuery query;
 QString res=QString::number(Cin);
    query.prepare(" SELECT CIN FROM Utilisateur where CIN = :cin AND MOTDEPASSE=:Motdepasse  ");
    query.bindValue(":cin",res);
    query.bindValue(":Motdepasse", Motdepasse );
    query.exec();
    while(query.next()==true)
    {
    i++;
    }

    if(i==0)
    {
        return  false;
    }

    return true ;

}

QSqlQueryModel*  Utilisateurs::Tri_Utilisateur_Nom()
{
        QSqlQueryModel* model =new QSqlQueryModel();
         QSqlQuery  *r = new QSqlQuery();
         r->prepare("SELECT * FROM Utilisateur ORDER BY NOM ASC");
         r->exec();
         model->setQuery(*r);
         return model ;
}

QSqlQueryModel* Utilisateurs::Tri_Utilisateur_Role()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *r = new QSqlQuery();
     r->prepare("SELECT * FROM Utilisateur ORDER BY ROLE DESC ");
     r->exec();
     model->setQuery(*r);
     return model ;
}

QSqlQueryModel* Utilisateurs::Rechercher_Utilisateur(const QString &str)
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery q;
q.prepare("SELECT * FROM Utilisateur where (Cin LIKE '"+str+"%' OR Nom LIKE '"+str+"%' OR Adresse LIKE '"+str+"%' OR Role LIKE '"+str+"%')")  ;
q.exec() ;
model->setQuery(q);
return model;
}

