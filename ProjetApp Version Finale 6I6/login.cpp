#include "login.h"
#include "ui_login.h"
#include <QObject>
#include <QMessageBox>
#include <QString>
#include "utilisateurs.h"
#include "menu.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("Smart Sport association");
    QPixmap pic("E:/Etudes/Projet C++/Projet C++/QTTTTTTTTTTTTTTT/img/football.png");
    ui->Login_pic->setPixmap(pic);
}

login::~login()
{
    delete ui;
}

void login::on_Connecter_clicked()
{
    int Cin =ui->login_cin->text().toInt();
    QString MotDepasse=ui->login_motdepasse->text();
    bool test =tmputilisateur.Login(Cin,MotDepasse);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("Connection Utilisateur "),
                              QObject::tr("Connecter avec Succes.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );

       hide();
       menu m;
       m.exec();


    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Connection Utilisateur"),
                   QObject::tr("non Connecter.\n"
 "Click Cancel to exit."),QMessageBox::Cancel );
    };
}
