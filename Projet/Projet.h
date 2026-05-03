// Fichier :     Projet.h
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Fenetre principale du jeu d'echecs.

#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <map>
#include <string>

#include "Echiquier.h"

namespace vue {

    class Projet : public QMainWindow {
        Q_OBJECT

    public:
        Projet(const std::string& nomDuFichier, QWidget* parent = nullptr );
        ~Projet() = default;

    protected:
        void paintEvent(QPaintEvent* event) override;
        void mousePressEvent(QMouseEvent* event) override;

    private:
        modele::Echiquier echiquier_;
        int ligneSelectionnee_ = -1;
        int colonneSelectionnee_ = -1;
        std::map<std::string, QPixmap> images_;
    };

}