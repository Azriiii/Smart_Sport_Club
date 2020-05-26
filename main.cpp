#include "first.h"
#include "connexion.h"
#include "menu.h"
#include <QApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    Connexion c;

     // topLevelLabel.show();
    c.createconnect();
    w.show();
    return a.exec();


}
