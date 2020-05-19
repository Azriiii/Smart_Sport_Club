 #include "crud_joueur.h"
#include "ui_crud_joueur.h"
#include "joueurs.h"
#include "QMessageBox"
#include<QSqlError>
#include <QDialog>
#include<QDebug>

crud_joueur::crud_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud_joueur)
{
    ui->setupUi(this);
    ui->tabjoueur->setModel(tmpjoueur.afficher());
}
/*crud_joueur::crud_joueur(QDialog *parent) :

    QDialog(parent),
    ui(new Ui::crud_joueur)
{
ui->setupUi(this);
ui->tabjoueur->setModel(tmpjoueur.afficher());
ui->comboBox->setModel(tmpjoueur.affichernom());
ui->comboBox->addItem("Trier par :");
ui->comboBox->addItem("ID");
ui->comboBox->addItem("Nom");
ui->comboBox->addItem("Prenom");
ui->comboBox->addItem("Poste");
ui->comboBox->addItem("Numéro");




}*/
crud_joueur::~crud_joueur()
{
    delete ui;
}

void crud_joueur::on_pushButton_16_clicked()
{   crud_joueur w;
    int id = ui->id->text().toInt();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString poste= ui->poste->text();
    int num= ui->num->text().toInt();
    joueurs e(id,nom,prenom,poste,num);
     bool test=e.ajouter();
    if(test)
    {
        ui->tabjoueur->setModel(tmpjoueur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Joueur"),
        QObject::tr("Joueur ajouté"), QMessageBox::Ok);


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un joueur"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);
    w.show();
}


void crud_joueur::on_pushButton_21_clicked()
{       crud_joueur w;

    int id = ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString poste=ui->poste->text();
    int num = ui->num->text().toInt();

    if (id==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner un joueur"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
         QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
         msgBox.setText("Voullez-vous vraiment supprimer "+nom+" de la liste ?");
         msgBox.exec();

         if (msgBox.clickedButton() == connectButton)
         {
             msgBox.close();

                 QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                             QObject::tr("Joueur supprimé"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
                w.show();}
        ui->tabjoueur->setModel(tmpjoueur.afficher());//refresh


}

void crud_joueur::on_pushButton_19_clicked()
{
    crud_joueur w;
        int id=ui->id->text().toInt();
        QSqlQuery qry;
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        QString poste=ui->poste->text();
        int num=ui->num->text().toInt();
        if (nom=="" || id ==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner un joueur"), QMessageBox::Ok);
        }
        else
        {
          /*  modification d;
           *d.setid(id);
            d.setnom(nom);
            d.setprenom(prenom);
            d.setposte(poste);
            d.setnum(num);

            d.exec(); */
            ui->id->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->prenom->setText(qry.value(2).toString());
            ui->poste->setText(qry.value(3).toString());
            ui->num->setText(qry.value(4).toString());
            bool test=tmpjoueur.modifier(id,nom,prenom,poste,num);
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier joueur"),
                            QObject::tr("Joueur modifié"), QMessageBox::Ok);

            }
            w.show();
        }
        ui->tabjoueur->setModel(tmpjoueur.afficher());
}

/*void crud_joueur::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery qry;

    qry.prepare("select * from joueur where nom = '"+arg1+"'");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->id->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->prenom->setText(qry.value(2).toString());
            ui->poste->setText(qry.value(2).toString());
            ui->num->setText(qry.value(2).toString());

        }
    }
    else
    {        QMessageBox::critical(this,tr("error"),qry.lastError().text());

    }
}*/

void crud_joueur::on_pushButton_clicked()
{
    QSqlQuery query;
        QString id= ui->lineEdit->text();
        id=id+"%";
        qDebug()<<id;
        query.prepare("SELECT * from joueurs where(id LIKE :id)");
        query.bindValue(":id",id);
        if(!query.exec())
        {
            qDebug()<<query.lastError();
        }
        QSqlQueryModel * modal= new QSqlQueryModel();
        modal->setQuery(query);
        qDebug()<<modal->rowCount();
        ui->tabjoueur->setModel(modal);
}
