 #include "crud_joueur.h"
#include "ui_crud_joueur.h"
#include "joueurs.h"
#include "QMessageBox"
#include<QSqlError>
#include <QDialog>
#include<QDebug>
#include<menu.h>
#include <QPainter>
#include <QPdfWriter>

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

    int idd = ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString poste=ui->poste->text();
    int num = ui->num->text().toInt();

    if (idd==0)
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
             tmpjoueur.supprimer(idd);
             ui->tabjoueur->setModel(tmpjoueur.afficher());
                 QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                             QObject::tr("Joueur supprimé"), QMessageBox::Ok);
                   w.show();
             /*msgBox.close();

                 QMessageBox::information(nullptr, QObject::tr("Supprimer une actualite"),
                             QObject::tr("Actualite supprimée"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
         w.show();*/
    }

}}

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
            //qDebug()<<query.lastError();
        }
        QSqlQueryModel * modal= new QSqlQueryModel();
        modal->setQuery(query);
        qDebug()<<modal->rowCount();
        ui->tabjoueur->setModel(modal);
}

void crud_joueur::on_pushButton_2_clicked()
{
    menu w;
    hide();
    w.exec();
}

void crud_joueur::on_pushButton_3_clicked()
{
    QPdfWriter pdf("C:/Users/fares/Desktop/joueur.pdf");
             QPainter painter(&pdf);
            int i = 4000;
                 painter.setPen(Qt::blue);
                 painter.setFont(QFont("Arial", 30));
                 painter.drawText(1100,1200,"Liste Des Joueurs");
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Arial", 15));
                // painter.drawText(1100,2000,afficheDC);
                 painter.drawRect(100,100,7300,2600);
                 //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                 painter.drawRect(0,3000,9600,500);
                 painter.setFont(QFont("Arial", 9));
                 painter.drawText(200,3300,"IDENTIFIANT");
                 painter.drawText(1300,3300,"NOM");
                 painter.drawText(2100,3300,"PRENOM");
                 painter.drawText(3200,3300,"POSTE");
                 painter.drawText(5300,3300,"NUMERO");
                 QSqlQuery query;
                 query.prepare("select * from joueurs");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(200,i,query.value(0).toString());
                     painter.drawText(1300,i,query.value(1).toString());
                     painter.drawText(2200,i,query.value(2).toString());
                     painter.drawText(3200,i,query.value(3).toString());
                     painter.drawText(4500,i,query.value(4).toString());
                    i = i + 500;
                 }
                 int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                          painter.end();
                     }
}
