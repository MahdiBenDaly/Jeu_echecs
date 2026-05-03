// Fichier :     main.cpp
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Point d'entree du programme.

#include "Projet.h"
#include "EcranAccueil.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    vue::EcranAccueil ecranAccueil;



    ecranAccueil.show();
    return app.exec();
}