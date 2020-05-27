QT       += core gui sql quickwidgets
QT       += network
QT      += printsupport
QT       +=multimedia
QT       +=widgets
QT       +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Abonnement.cpp \
    Abonnementwindow.cpp \
    Accueil.cpp \
    Cadeau.cpp \
    Cadeauwindow.cpp \
    GestionMatchEquipe.cpp \
    abonne.cpp \
    actualite.cpp \
    bienvenu.cpp \
    connexion.cpp \
    crud_actualite.cpp \
    crud_evenement.cpp \
    crud_joueur.cpp \
    crud_materiel.cpp \
    don.cpp \
    donateurcontroller.cpp \
    doncontroller.cpp \
    equipe.cpp \
    evenement.cpp \
    gestion.cpp \
    gestionutlisateurtournois.cpp \
    joueurs.cpp \
    login.cpp \
    main.cpp \
    first.cpp \
    match.cpp \
    materiel.cpp \
    menu.cpp \
    note_Cadeau.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    tournois.cpp \
    utilisateurs.cpp

HEADERS += \
    Abonnement.h \
    Abonnementwindow.h \
    Accueil.h \
    Cadeau.h \
    Cadeauwindow.h \
    GestionMatchEquipe.h \
    abonne.h \
    actualite.h \
    bienvenu.h \
    connexion.h \
    crud_actualite.h \
    crud_evenement.h \
    crud_joueur.h \
    crud_materiel.h \
    don.h \
    donateurcontroller.h \
    doncontroller.h \
    equipe.h \
    evenement.h \
    first.h \
    gestion.h \
    gestionutlisateurtournois.h \
    joueurs.h \
    login.h \
    match.h \
    materiel.h \
    menu.h \
    note_Cadeau.h \
    qcustomplot.h \
    smtp.h \
    tournois.h \
    utilisateurs.h

FORMS += \
    Abonnementwindow.ui \
    Accueil.ui \
    Cadeauwindow.ui \
    GestionMatchEquipe.ui \
    bienvenu.ui \
    crud_actualite.ui \
    crud_evenement.ui \
    crud_joueur.ui \
    crud_materiel.ui \
    don.ui \
    first.ui \
    gestion.ui \
    gestionutlisateurtournois.ui \
    login.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/logo.png

RESOURCES += \
    images.qrc \
    musique.qrc \
    resource.qrc
