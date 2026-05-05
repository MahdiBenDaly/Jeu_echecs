// Fichier :     EcranAccueil.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Ecran d'accueil du jeu d'echecs.

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

namespace vue {

    class EcranAccueil : public QWidget {
        Q_OBJECT
    public:
        EcranAccueil();

    private:
        void setUpUI();

        QPushButton* boutonPartieNormale_ = new QPushButton("Nouvelle partie");
        QPushButton* boutonFinDePartie_ = new QPushButton("Fin de partie");
        QPushButton* boutonFermer_ = new QPushButton("Quitter");



        QHBoxLayout* ligneTitre = new QHBoxLayout;
        QVBoxLayout* layout_ = new QVBoxLayout;
    };

}