#include "GestionMatchEquipe.h"
#include "ui_GestionMatchEquipe.h"
#include "match.h"
#include "menu.h"
#include "equipe.h"
#include "QMessageBox"
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QTextStream>

GestionMatchEquipe::GestionMatchEquipe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GestionMatchEquipe)
{

    ui->setupUi(this);

    ui->data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->data_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DATE->setDate(QDate::currentDate());
    match tmp;
    equipe tmp2;
    ui->data->setModel(tmp.afficher());
    ui->id_equipe1->setModel(tmp2.getIDs());
    ui->id_equipe2->setModel(tmp2.getIDs());
    ui->data_2->setModel(tmp2.afficher());
    ui->id_match->setModel(tmp.getIDs());
}

GestionMatchEquipe::~GestionMatchEquipe()
{
    delete ui;
}


void GestionMatchEquipe::on_pb_ajouter_clicked()
{
 match tmp(ui->id_match2->text().toInt(),ui->lieu->text(),ui->id_equipe1->currentText().toInt(),ui->id_equipe2->currentText().toInt(),ui->DATE->date());


    if (ui->id_match2->text().isEmpty())
    {
              QMessageBox::information(this," ERREUR "," Verifier le champ ID MATCH !") ;
    }
     else if (ui->lieu->text().isEmpty())
     {
              QMessageBox::information(this," ERREUR "," Verifier le champ LIEU !") ;

     }


    else if(tmp.ajouter())
    {

        ui->data->setModel(tmp.afficher());
        ui->lineEdit_id_6->setText("");
        ui->id_match->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void GestionMatchEquipe::on_pb_supprimer_3_clicked()
{
    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un Match du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        match tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->lieu->text(),ui->id_equipe1->currentText().toInt(),ui->id_equipe2->currentText().toInt(),ui->DATE->date());
        if(tmp.modifier())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->id_match->setModel(tmp.getIDs());
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

void GestionMatchEquipe::on_pb_supprimer_4_clicked()
{

    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un Match du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        match tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->lieu->text(),ui->id_equipe1->currentText().toInt(),ui->id_equipe2->currentText().toInt(),ui->DATE->date());
        if(tmp.supprimer())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->id_match->setModel(tmp.getIDs());
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

void GestionMatchEquipe::on_data_clicked(const QModelIndex &index)
{
    ui->id_match2->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toString());
    ui->lieu->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),1)).toString());
    ui->id_equipe1->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),2)).toString());
    ui->id_equipe2->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toString());

    ui->DATE->setDate(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),4)).toDate());

}

void GestionMatchEquipe::on_lineEdit_id_6_textChanged(const QString &arg1)
{

     match tmp;
     if(ui->lineEdit_id_6->text()!="")
     {

     //ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
         QString b=ui->comboBox->currentText();
         QString a=ui->lineEdit_id_6->text();
         ui->data->setModel(tmp.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
     }else
     ui->data->setModel(tmp.afficher());
}

void GestionMatchEquipe::on_comboBox_currentTextChanged(const QString &arg1)
{
    match tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
    else
    ui->data->setModel(tmp.afficher());
}



void GestionMatchEquipe::on_pb_ajouter_2_clicked()
{
    equipe tmp(ui->id_equipe->text().toInt(),ui->NOM->text(),ui->division->text(),ui->id_match->currentText().toInt(),ui->type->text());

    if (ui->id_equipe->text().isEmpty())
    {

              QMessageBox::information(this," ERREUR "," Verifier le champ ID EQUIPE !") ;

    } else if (ui->NOM->text().isEmpty())
     {
              QMessageBox::information(this," ERREUR "," Verifier le champ NOM !") ;

     }
   else if (ui->division->text().isEmpty())
    {
              QMessageBox::information(this," ERREUR "," Verifier le champ DIVISION !") ;
    }
     else if (ui->type->text().isEmpty())
     {
              QMessageBox::information(this," ERREUR "," Verifier le champ TYPE !") ;

     }



   else if(tmp.ajouter())
    {
        ui->data_2->setModel(tmp.afficher());
        ui->lineEdit_id_7->setText("");
        ui->id_equipe1->setModel(tmp.getIDs());
        ui->id_equipe2->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GestionMatchEquipe::on_pb_supprimer_5_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un Don du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        equipe tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->NOM->text(),ui->division->text(),ui->id_match->currentText().toInt(),ui->type->text());
        if(tmp.modifier())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->id_equipe1->setModel(tmp.getIDs());
            ui->id_equipe2->setModel(tmp.getIDs());

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

void GestionMatchEquipe::on_pb_supprimer_6_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un Donateur du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        equipe tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->NOM->text(),ui->division->text(),ui->id_match->currentText().toInt(),ui->type->text());
        if(tmp.supprimer())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->id_equipe1->setModel(tmp.getIDs());
            ui->id_equipe2->setModel(tmp.getIDs());

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

void GestionMatchEquipe::on_lineEdit_id_7_textChanged(const QString &arg1)
{
    equipe tmp;
    if(ui->lineEdit_id_7->text()!="")
    {
   // ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
        QString b=ui->comboBox_2->currentText();
        QString a=ui->lineEdit_id_7->text();
        ui->data_2->setModel(tmp.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
    }else
    ui->data_2->setModel(tmp.afficher());
}




void GestionMatchEquipe::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    equipe tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
    else
    ui->data_2->setModel(tmp.afficher());
}

void GestionMatchEquipe::on_data_2_clicked(const QModelIndex &index)
{
    ui->id_equipe->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toString());
    ui->NOM->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),1)).toString());
    ui->division->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),2)).toString());
    ui->id_match->setCurrentText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),3)).toString());
    ui->type->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),4)).toString());
}


void GestionMatchEquipe::on_id_tri_currentTextChanged(const QString &arg1)
{
    match tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
    else
    ui->data->setModel(tmp.displayClause("ORDER BY "+ui->id_tri->currentText()));
}

void GestionMatchEquipe::on_id_tri2_currentTextChanged(const QString &arg1)
{
    equipe tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
    else
    ui->data_2->setModel(tmp.displayClause("ORDER BY "+ui->id_tri2->currentText()));
}

void GestionMatchEquipe::on_pushButton_2_clicked()
{
    {
         //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:/Users/Rafik/Desktop/match.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1500,1400,"Liste Des match");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Rafik/Desktop/img.jpg"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(300,3300,"ID MATCH");
                           painter.drawText(2300,3300,"LIEU");
                           painter.drawText(4300,3300,"ID EQUIPE1");
                           painter.drawText(6300,3300,"ID EQUIPE2");
                           painter.drawText(8300,3300,"DATE");
                           QSqlQuery query;
                           query.prepare("select * from match");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(300,i,query.value(0).toString());
                               painter.drawText(2300,i,query.value(1).toString());
                               painter.drawText(4500,i,query.value(2).toString());
                               painter.drawText(6500,i,query.value(3).toString());
                               painter.drawText(8000,i,query.value(4).toString());
                              i = i + 500;
                           }
                           int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                               if (reponse == QMessageBox::Yes)
                               {

                                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Rafik/Desktop/match.pdf"));

                                   painter.end();
                               }
                               if (reponse == QMessageBox::No)
                               {
                                    painter.end();
                               }
        }

}


void GestionMatchEquipe::on_pushButton24_clicked()
{
        hide();
        menu c;
        c.exec();
}

void GestionMatchEquipe::on_pushButton24_2_clicked()
{
    hide();
    menu c;
    c.exec();
}

void GestionMatchEquipe::on_pushButton_33_clicked()
{
    {
         //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:/Users/Rafik/Desktop/equipe.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1500,1400,"Liste Des equipe");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Rafik/Desktop/img.jpg"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(300,3300,"ID EQUIPE");
                           painter.drawText(2300,3300,"NOM");
                           painter.drawText(4300,3300,"DIVISION");
                           painter.drawText(6300,3300,"ID MATCH");
                           painter.drawText(8300,3300,"TYPE");
                           QSqlQuery query;
                           query.prepare("select * from equipe");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(300,i,query.value(0).toString());
                               painter.drawText(2300,i,query.value(1).toString());
                               painter.drawText(4500,i,query.value(2).toString());
                               painter.drawText(6500,i,query.value(3).toString());
                               painter.drawText(8000,i,query.value(4).toString());
                              i = i + 500;
                           }
                           int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                               if (reponse == QMessageBox::Yes)
                               {

                                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Rafik/Desktop/equipe.pdf"));

                                   painter.end();
                               }
                               if (reponse == QMessageBox::No)
                               {
                                    painter.end();
                               }
        }
}
