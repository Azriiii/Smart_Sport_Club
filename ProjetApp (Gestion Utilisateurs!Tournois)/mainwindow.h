#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "utilisateurs.h"
#include "tournois.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Login_clicked();

    void on_Gestion_utilisateurs_clicked();

    void on_Gestion_tournois_clicked();

    void on_Retour_tournois_clicked();

    void on_Retour_utilisateur_clicked();

    void on_Ajouter_Utilisateur_clicked();

    void on_Afficher_Utilisateur_clicked();

    void on_Supprimer_Utilisateur_clicked();

    void on_Ajouter_Tournois_clicked();

    void on_Supprimer_Tournois_clicked();

    void on_Afficher_Tounrois_clicked();

    void on_TabUtilisatuer_clicked(const QModelIndex &index);

    void on_Modifier_Utilisateur_clicked();

    void on_TabTournois_clicked(const QModelIndex &index);

    void on_Modifier_Tournois_clicked();

    void on_Rechercher_utilisateur_textChanged(const QString &arg1);

    void on_Tri_utilisateur_activated(const QString &arg1);

    void on_Tri_Tournois_activated(const QString &arg1);


private:
    Ui::MainWindow *ui;
    Utilisateurs tmputilisateur;
    Tournois tmptournois;
};
#endif // MAINWINDOW_H
