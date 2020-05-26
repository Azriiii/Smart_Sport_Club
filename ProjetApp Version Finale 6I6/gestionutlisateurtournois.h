#ifndef GESTIONUTLISATEURTOURNOIS_H
#define GESTIONUTLISATEURTOURNOIS_H

#include <QDialog>
#include "utilisateurs.h"
#include "tournois.h"

namespace Ui {
class GestionUtlisateurTournois;
}

class GestionUtlisateurTournois : public QDialog
{
    Q_OBJECT

public:
    explicit GestionUtlisateurTournois(QWidget *parent = nullptr);
    ~GestionUtlisateurTournois();

private slots:
    void on_Gestion_Utilisateur_clicked();

    void on_Gestion_Tournois_clicked();

    void on_Retour_Menu_clicked();

    void on_TabUtilisatuer_clicked(const QModelIndex &index);

    void on_Ajouter_Utilisateur_clicked();

    void on_Modifier_Utilisateur_clicked();

    void on_Supprimer_Utilisateur_clicked();

    void on_Afficher_Utilisateur_clicked();

    void on_Tri_utilisateur_activated(const QString &arg1);

    void on_Rechercher_utilisateur_textChanged(const QString &arg1);

    void on_Retour_Utilisateur_clicked();

    void on_TabTournois_clicked(const QModelIndex &index);

    void on_Ajouter_Tournois_clicked();

    void on_Modifier_Tournois_clicked();

    void on_Supprimer_Tournois_clicked();

    void on_Afficher_Tounrois_clicked();

    void on_Tri_Tournois_activated(const QString &arg1);

    void on_Retour_tournois_clicked();

private:
    Ui::GestionUtlisateurTournois *ui;
    Utilisateurs tmputilisateur;
    Tournois tmptournois ;
};

#endif // GESTIONUTLISATEURTOURNOIS_H
