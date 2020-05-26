#include "gestionutlisateurtournois.h"
#include "ui_gestionutlisateurtournois.h"
#include "menu.h"

GestionUtlisateurTournois::GestionUtlisateurTournois(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionUtlisateurTournois)
{
    ui->setupUi(this);
    this->setWindowTitle("Smart Sport association");
}

GestionUtlisateurTournois::~GestionUtlisateurTournois()
{
    delete ui;
}

void GestionUtlisateurTournois::on_Gestion_Utilisateur_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionUtlisateurTournois::on_Gestion_Tournois_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionUtlisateurTournois::on_Retour_Menu_clicked()
{
    menu w ;
    hide();
    w.exec();

}

void GestionUtlisateurTournois::on_TabUtilisatuer_clicked(const QModelIndex &index)
{
    ui->Cin->setText(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),0)).toString());
    ui->Nom->setText(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),1)).toString());
    ui->Motdepasse->setText(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),2)).toString());
    ui->Adresse->setText(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),3)).toString());
    ui->comboBox->setCurrentText(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),4)).toString());
}

void GestionUtlisateurTournois::on_Ajouter_Utilisateur_clicked()
{
    int Cin =ui->Cin->text().toInt();
    QString Nom= ui->Nom->text();
    QString MotDePasse= ui->Motdepasse->text();
    QString Adresse= ui->Adresse->text();
    QString Role=ui->comboBox->currentText();
  Utilisateurs u(Cin,Nom,MotDePasse,Adresse,Role);
  bool test=u.Ajouter_Utilisateur();
  if(test)
{ ui->TabUtilisatuer->setModel(tmputilisateur.Afficher_utilisateur());
QMessageBox::information(nullptr, QObject::tr("Ajouter un utilisateur"),
                  QObject::tr("utilisateur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un utilisateur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void GestionUtlisateurTournois::on_Modifier_Utilisateur_clicked()
{
    if(ui->TabUtilisatuer->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un utilisateur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Utilisateurs tmp(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),0)).toInt(),ui->Nom->text(),ui->Motdepasse->text(),ui->Adresse->text(),ui->comboBox->currentText());
        if(tmp.Modifier_uitlisateur())
        {
            ui->TabUtilisatuer->setModel(tmp.Afficher_utilisateur());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void GestionUtlisateurTournois::on_Supprimer_Utilisateur_clicked()
{
    if(ui->TabUtilisatuer->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un utilisateur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Utilisateurs tmp(ui->TabUtilisatuer->model()->data(ui->TabUtilisatuer->model()->index(ui->TabUtilisatuer->currentIndex().row(),0)).toInt(),ui->Nom->text(),ui->Motdepasse->text(),ui->Adresse->text(),ui->comboBox->currentText());
        if(tmp.Supprimer_utilisateur())
        {
            ui->TabUtilisatuer->setModel(tmp.Afficher_utilisateur());

            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void GestionUtlisateurTournois::on_Afficher_Utilisateur_clicked()
{
    ui->TabUtilisatuer->setModel(tmputilisateur.Afficher_utilisateur());
}

void GestionUtlisateurTournois::on_Tri_utilisateur_activated(const QString &arg1)
{
    QSqlQueryModel* model=tmputilisateur.Tri_Utilisateur_Nom();
        ui->TabUtilisatuer->setModel(model);
        if(ui->Tri_utilisateur->currentIndex())
        {
            QSqlQueryModel* model=tmputilisateur.Tri_Utilisateur_Role();
                ui->TabUtilisatuer->setModel(model);
        }
}

void GestionUtlisateurTournois::on_Rechercher_utilisateur_textChanged(const QString &arg1)
{
    QString str=ui->Rechercher_utilisateur->text();
    QSqlQueryModel* model=tmputilisateur.Rechercher_Utilisateur(str);
        ui->TabUtilisatuer-> setModel(model);
}

void GestionUtlisateurTournois::on_Retour_Utilisateur_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionUtlisateurTournois::on_TabTournois_clicked(const QModelIndex &index)
{
    ui->ID->setText(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),0)).toString());
    ui->dateEdit->setDate(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),1)).toDate());
    ui->Nombre_equipe->setText(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),2)).toString());
    ui->Adresse_Tournois->setText(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),3)).toString());
}

void GestionUtlisateurTournois::on_Ajouter_Tournois_clicked()
{
    int Id=ui->ID->text().toInt();
    QDate Date=ui->dateEdit->date();
    int NombreEquipe=ui->Nombre_equipe->text().toInt();
    QString Adresse= ui->Adresse_Tournois->text();
    Tournois T(Id,Date,NombreEquipe,Adresse);
    bool test=T.Ajouter_Tournois();
    if(test)
  {
        ui->TabTournois->setModel(tmptournois.Afficher_Tournois());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un Tournois"),
                    QObject::tr("Tournois ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Tournois"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void GestionUtlisateurTournois::on_Modifier_Tournois_clicked()
{
    if(ui->TabTournois->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification Tounrois"),
                          QObject::tr("Veuillez Choisir un utilisateur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Tournois tmp(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),0)).toInt(),ui->dateEdit->date(),ui->Nombre_equipe->text().toInt(),ui->Adresse_Tournois->text());
        if(tmp.Modifier_Tournois())
        {
            ui->TabTournois->setModel(tmp.Afficher_Tournois());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void GestionUtlisateurTournois::on_Supprimer_Tournois_clicked()
{
    if(ui->TabTournois->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification Tounrois"),
                          QObject::tr("Veuillez Choisir un utilisateur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Tournois tmp(ui->TabTournois->model()->data(ui->TabTournois->model()->index(ui->TabTournois->currentIndex().row(),0)).toInt(),ui->dateEdit->date(),ui->Nombre_equipe->text().toInt(),ui->Adresse_Tournois->text());
        if(tmp.Supprimer_Torunois())
        {
            ui->TabTournois->setModel(tmp.Afficher_Tournois());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void GestionUtlisateurTournois::on_Afficher_Tounrois_clicked()
{
     ui->TabTournois->setModel(tmptournois.Afficher_Tournois());
}

void GestionUtlisateurTournois::on_Tri_Tournois_activated(const QString &arg1)
{
    QSqlQueryModel* model=tmptournois.Tri_Tournois_ID();
        ui->TabTournois->setModel(model);
        if(ui->Tri_Tournois->currentIndex()==1)
        {
            QSqlQueryModel* model=tmptournois.Tri_Tournois_Date();
                ui->TabTournois->setModel(model);
        }
        else if (ui->Tri_Tournois->currentIndex()==2)
        {
            QSqlQueryModel* model=tmptournois.Tri_Tournois_Equipe();
                ui->TabTournois->setModel(model);
        }
}

void GestionUtlisateurTournois::on_Retour_tournois_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
