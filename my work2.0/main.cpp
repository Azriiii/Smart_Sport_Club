#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "bienvenu.h"
#include "Cadeau.h"
#include "Cadeauwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bienvenu b ;
    Connexion c;
    Cadeau M ;
    bool test=c.ouvrirConnexion();
    b.show();
    if(test)
    {//w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
