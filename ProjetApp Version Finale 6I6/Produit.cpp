#include "Produit.h"
#include "QSqlQuery"
#include "ui_Smart.h"
#include "qcustomplot.h"
#include <QDebug>

/*Smart::Smart(QWidget *parent) :  QDialog(parent), ui(new Ui::Smart)
{
    ui->setupUi(this);

    ui->tableView->setModel((tmpproduit.afficher()));


}
*/
Smart::Smart(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Smart)


{
   // ui->setupUi(this);
    ui->setupUi(this);
    ui->tableView->setModel((tmpproduit.afficher()));

}
Smart::~Smart()
{
    delete ui;
}

void Smart::on_b1_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void Smart::on_b2_7_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
}
void Smart::on_icon2_7_clicked()
{
ui->stackedWidget->setCurrentIndex(10);
}

void Smart::on_b2_8_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
}

void Smart::on_b1_9_clicked()
{
ui->stackedWidget->setCurrentIndex(3);
}

void Smart::on_icon1_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(5);
}

void Smart::on_b2_15_clicked()
{
 ui->stackedWidget->setCurrentIndex(4);
}

void Smart::on_icon2_13_clicked()
{
ui->stackedWidget->setCurrentIndex(6);
}

void Smart::on_icon2_6_clicked()
{
ui->stackedWidget->setCurrentIndex(6);
}

void Smart::on_icon3_5_clicked()
{
ui->stackedWidget->setCurrentIndex(7);
}


void Smart::on_icon4_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tableView_3->setModel(tmpCadeau.afficherCadeau());//refresh
    ui->tableView->setModel(tmpproduit.afficher());

}

void Smart::on_icon3_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);


}

void Smart::on_icon4_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tableView_3->setModel(tmpCadeau.afficherCadeau());//refresh
    ui->tableView->setModel(tmpproduit.afficher());

}

void Smart::on_icon4_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}



void Smart::on_icon4_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void Smart::on_icon2_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void Smart::on_icon3_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void Smart::on_icon4_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}


void Smart::on_icon3_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void Smart::on_icon4_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tableView_3->setModel(tmpCadeau.afficherCadeau());//refresh
    ui->tableView->setModel(tmpproduit.afficher());

}

void Smart::on_icon2_37_clicked()
{
  ui->stackedWidget->setCurrentIndex(6);
}

void Smart::on_icon4_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void Smart::on_confirm_11_clicked()
{
    Produit p(ui->lineEdit_reff->text().toInt(),
              ui->lineEdit_prix->text().toFloat(),
              ui->lineEdit_type->text());

    bool test=p.produit_ajouter();
    notifier = new QSystemTrayIcon(this);
        notifier->setIcon(QIcon("notification.png"));
        notifier->show();
        if(test)
        {
        notifier->showMessage("Ok","Produit ajoute",QSystemTrayIcon::Warning,10000);
 }
  if (ui->lineEdit_reff->text().isEmpty())
   {

       QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Reference!!!!") ;

   }
          if (ui->lineEdit_prix->text().isEmpty())
           {

               QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;

           }
  if (ui->lineEdit_type->text().isEmpty())
   {

       QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP type !!!!") ;

   }

  if(test)
{
      ui->tableView->setModel(tmpproduit.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(0, qApp->tr("Ajout"),

                      qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

  ui->lineEdit_reff->setText("");
   ui->lineEdit_prix->setText("");
   ui->lineEdit_type->setText("");
}

void Smart::on_confirm_13_clicked()
{
    Cadeau d(ui->lineEdit_numde->text().toInt(),
              ui->lineEdit_typede->text());

    bool test=d.Cadeau_ajouter();
    notifier = new QSystemTrayIcon(this);
        notifier->setIcon(QIcon("notification.png"));
        notifier->show();
        if(test)
        {
        notifier->showMessage("Ok","Cadeau ajoute",QSystemTrayIcon::Warning,10000);
 }
    if (ui->lineEdit_numde->text().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP numero!!!!") ;

     }
            if (ui->lineEdit_typede->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP type!!!!") ;

             }


    if(test)
  {
        ui->tableView_3->setModel(tmpCadeau.afficherCadeau());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un Cadeau"),
                    QObject::tr("Cadeau ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(0, qApp->tr("Ajout"),

                        qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    ui->lineEdit_numde->setText("");
     ui->lineEdit_typede->setText("");


}

void Smart::on_confirm_18_clicked()
{

    int reff = ui->lineEdit_reff_3->text().toInt();

    bool test=tmpproduit.supprimer(reff);
    if(test)
     {ui->tableView->setModel(tmpproduit.afficher());//refresh





        QString str = " Vous voulez vraiment supprimer \n le produit ayant pour reference :"+ ui->lineEdit_reff_3->text();
                      int ret = QMessageBox::question(this, tr("Produit"),str,QMessageBox::Ok|QMessageBox::Cancel);

                      switch (ret) {
                        case QMessageBox::Ok:
                            if (tmpproduit.supprimer(reff))
                                QMessageBox ::information(0, qApp->tr("Suppression"),
                                                          qApp->tr("le produit a été supprimé"), QMessageBox::Ok);

//ui->listView->setModel(tmpproduit.afficher());//refresh
                          break;
                        case QMessageBox::Cancel:

                            break;
                        default:
                            // should never be reached
                            break;
                      }
    }
                      else
                                {

                                    QMessageBox::critical(0, qApp->tr("Suppression"),
                                        qApp->tr("produit non trouvé"), QMessageBox::Cancel);

                                }




}



void Smart::on_confirm_24_clicked()
{
    int num = ui->lineEdit_numde_2->text().toInt();
    bool test=tmpCadeau.supprimer(num);
    if(test)
     {
        //ui->tableView->setModel(tmpproduit.afficher());//refresh

        QString str = " Vous voulez vraiment supprimer \n le Cadeau ayant pour numéro :"+ ui->lineEdit_numde_2->text();
                      int ret = QMessageBox::question(this, tr("Cadeau"),str,QMessageBox::Ok|QMessageBox::Cancel);

                      switch (ret) {
                        case QMessageBox::Ok:
                            if (tmpCadeau.supprimer(num))

                                QMessageBox ::information(0, qApp->tr("Suppression"),
                                                          qApp->tr("le Cadeau a été supprimé"), QMessageBox::Ok);

ui->tableView_3->setModel(tmpCadeau.afficherCadeau());//refresh
                          break;
                        case QMessageBox::Cancel:

                            break;
                        default:
                            // should never be reached
                            break;
                      }
    }

    else


                                      QMessageBox::critical(0, qApp->tr("Suppression"),
                                        qApp->tr("Cadeau non trouvé"), QMessageBox::Cancel);




}

void Smart::on_icon3_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->tableView_2->setModel(tmpproduit.sortid());
 //   ui->tableView_2->setModel(tmpproduit.afficher());



}

void Smart::on_icon3_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->tableView_2->setModel(tmpproduit.sortid());
   // ui->tableView_2->setModel(tmpproduit.afficher());


}

void Smart::on_icon4_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    // set dark background gradient:
       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));

       // create empty bar chart objects:
       QCPBars *regen = new QCPBars(ui->customPlot->xAxis,ui-> customPlot->yAxis);

       regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders

       regen->setStackingGap(1);

       // set names and colors:

       regen->setName("statistique sur Produit");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       int i=0;
       QSqlQuery q;
           q.exec("select type from produit ");
           while (q.next())
           {
               QString type= q.value(0).toString();
               i++;
               ticks<<i;
               labels <<type;
               qDebug()<<":type"<<type<<endl;

           }






       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 4);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->customPlot->yAxis->setRange(0,100);
       ui->customPlot->yAxis->setPadding(2); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Produit");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
       ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

       // Add data:
       QVector<double> regenData;

       int j=0;
       QSqlQuery q2;
           q2.exec("select prix from produit");
           while (q2.next())
           {
               float prix= q2.value(0).toFloat();
               qDebug()<<"prix :"<<prix<<endl;
               j++;
               regenData <<prix;

           }


       regen->setData(ticks, regenData);


       // setup legend:
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}

void Smart::on_confirm_19_clicked()
{

    int reff = ui->LineEdit_Ref->text().toInt();
            QString type= ui->LineEdit_type->text();
            float prix=ui->lineEdit_prix_3->text().toFloat();


           //QString newmodel = var ;

 Produit *p= new Produit( reff, prix, type);



 if (p->modifierproduit()  )
 {
    ui->tableView->setModel(tmpproduit.afficher());
     QMessageBox::information(0, qApp->tr("Update"),
         qApp->tr("Successful"), QMessageBox::Ok);}
 else
     QMessageBox::critical(0, qApp->tr("Update"),
         qApp->tr("you got some problems there check out "), QMessageBox::Cancel);


}
 /*        int reff = ui->LineEdit_Ref->text().toInt();
        QString type= ui->LineEdit_type->text();
        float prix=ui->lineEdit_prix_3->text().toFloat();

    Produit *p= new Produit(reff,prix,type);

    if(p->editproduit())
    {ui->tableView->setModel(tmpproduit.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                    QObject::tr("produit modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("modifier un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
     }
     */




void Smart::on_b2_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void Smart::on_b1_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b1_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_confirm_20_clicked()
{
    QString type=ui->LineEdit_type_2->text();
    int num=ui->LineEdit_Ref_2->text().toInt();
    Cadeau *d = new Cadeau(num, type);
    notifier = new QSystemTrayIcon(this);
        notifier->setIcon(QIcon("notification.png"));
        notifier->show();
        if(d->modifier())
        {
        notifier->showMessage("Ok","Cadeau modifier",QSystemTrayIcon::Warning,10000);
 }
    if (d->modifier()  )
    {
       ui->tableView_2->setModel(tmpCadeau.afficherCadeau());
        QMessageBox::information(0, qApp->tr("Update"),
            qApp->tr("Successful"), QMessageBox::Ok);}
    else
        QMessageBox::critical(0, qApp->tr("Update"),
            qApp->tr("you got some problems there check out "), QMessageBox::Cancel);
}



void Smart::on_b2_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void Smart::on_b2_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void Smart::on_icon3_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->tableView_2->setModel(tmpproduit.sortid());
}

void Smart::on_icon1_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

    // set dark background gradient:
       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));

       // create empty bar chart objects:
       QCPBars *regen = new QCPBars(ui->customPlot->xAxis,ui-> customPlot->yAxis);

       regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders

       regen->setStackingGap(1);

       // set names and colors:

       regen->setName("statistique sur Produit");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       int i=0;
       QSqlQuery q;
           q.exec("select type from produit ");
           while (q.next())
           {
               QString type= q.value(0).toString();
               i++;
               ticks<<i;
               labels <<type;
               qDebug()<<":type"<<type<<endl;

           }






       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 4);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->customPlot->yAxis->setRange(0,100);
       ui->customPlot->yAxis->setPadding(2); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Produit");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
       ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

       // Add data:
       QVector<double> regenData;

       int j=0;
       QSqlQuery q2;
           q2.exec("select prix from produit");
           while (q2.next())
           {
               float prix= q2.value(0).toInt();
               qDebug()<<"prix :"<<prix<<endl;
               j++;
               regenData <<prix;

           }


       regen->setData(ticks, regenData);


       // setup legend:
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);



}

void Smart::on_icon4_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void Smart::on_confirm_21_clicked()
{

    notifier = new QSystemTrayIcon(this);
        notifier->setIcon(QIcon("notification.png"));
        notifier->show();

    int reff =ui->lineEdit_reff_2->text().toInt();

    if (ui->lineEdit_reff_2->text().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Reference  !!!!") ;

     }
    else{
            QSqlQueryModel *model =tmpproduit.chercher_produit(reff);
          int IDref = model->data(model->index(0,0)).toInt();
           qDebug()<<(IDref);
            if(reff == IDref)
            {
                notifier->showMessage("Ok","Produit Trouvé",QSystemTrayIcon::Warning,10000);

                ui->tableView_4->show();
                ui->tableView_4->setModel(model);
            }
             else
            {
                QMessageBox::critical(0, qApp->tr("Recherche"),
                    qApp->tr("reference non trouvé"), QMessageBox::Ok);

}
}
}

void Smart::on_icon4_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    // set dark background gradient:
       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));

       // create empty bar chart objects:
       QCPBars *regen = new QCPBars(ui->customPlot->xAxis,ui-> customPlot->yAxis);

       regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders

       regen->setStackingGap(1);

       // set names and colors:

       regen->setName("statistique sur Produit");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       int i=0;
       QSqlQuery q;
           q.exec("select type from produit ");
           while (q.next())
           {
               QString type= q.value(0).toString();
               i++;
               ticks<<i;
               labels <<type;
               qDebug()<<":type"<<type<<endl;

           }






       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 4);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->customPlot->yAxis->setRange(0,100);
       ui->customPlot->yAxis->setPadding(2); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Produit");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
       ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

       // Add data:
       QVector<double> regenData;

       int j=0;
       QSqlQuery q2;
           q2.exec("select prix from produit");
           while (q2.next())
           {
               float prix= q2.value(0).toFloat();
               qDebug()<<"prix :"<<prix<<endl;
               j++;
               regenData <<prix;

           }


       regen->setData(ticks, regenData);


       // setup legend:
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);



}



void Smart::on_b2_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void Smart::on_update_label_clicked()
{
    /*
data=A.read_from_arduino();
 //   ui->lcdNumber->display(sensor_reading);
ui->label_2->setText(data);
*/

    QStringList buffersplit= serial.split(",");
    if(buffersplit.length()<3)
       {

        serial+=QString::fromStdString(data.toStdString());

       }
    else
    {   qDebug()<<buffersplit;
        ui->humidite->display(buffersplit[0]);


        ui->lcdnumber->display(buffersplit[1]);


          serial="";
                  }


}



void Smart::on_b2_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b2_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void Smart::on_b1_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Smart::on_b2_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void Smart::on_push_clicked()
{
    QString link="https://www.teskerti.tn/";
    QDesktopServices::openUrl(link);


}

