// Fichier :     main.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Point d'entree du programme.

#include "Projet.h"
#include "EcranAccueil.h"

#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QDir>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


#ifdef Q_OS_MACOS
    const QString assetsDir = QCoreApplication::applicationDirPath() + "/../Resources";
#else
    const QString assetsDir = QCoreApplication::applicationDirPath();
#endif
    const QDir resources(assetsDir);
    if (resources.exists("images") && resources.exists("scenarios")) {
        QDir::setCurrent(resources.absolutePath());
    }

    vue::EcranAccueil ecranAccueil;
    ecranAccueil.show();
    return app.exec();
}
