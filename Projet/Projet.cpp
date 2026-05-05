// Fichier :     Projet.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de la fenetre principale.

#include "Projet.h"
#include <QPainter>
#include <QMouseEvent>

#include "Roi.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Dame.h"

using namespace modele;
using namespace vue;
using namespace std;

const int TAILLE_CASE = 80;
const int TAILLE_BORDURE = 30;
const int TAILLE_PIECE = TAILLE_CASE - 5;

const QColor marronClair(240, 217, 181);
const QColor marronFonce(181, 136, 99);
const QColor jaune(255, 255, 0);

bool mettreCaseJaune = false;

Projet::Projet(const string& nomDuFichier, QWidget* parent) : QMainWindow(parent), echiquier_(nomDuFichier) {
    setWindowIcon(QIcon("images/roiBlanc.png"));
    setWindowTitle("Echecs");

    setFixedSize(8 * TAILLE_CASE + 2 * TAILLE_BORDURE, 8 * TAILLE_CASE + 2 * TAILLE_BORDURE);

    images_["roiBlanc"] = QPixmap{ "images/roiBlanc.png" };
    images_["tourBlanc"] = QPixmap{ "images/tourBlanc.png" };
    images_["cavalierBlanc"] = QPixmap{ "images/cavalierBlanc.png" };
    images_["fouBlanc"] = QPixmap{ "images/fouBlanc.png" };
    images_["dameBlanc"] = QPixmap{ "images/dameBlanc.png" };
    images_["PionBlanc"] = QPixmap{ "images/pionBlanc.png" };


    images_["roiNoir"] = QPixmap{ "images/roiNoir.png" };
    images_["tourNoir"] = QPixmap{ "images/tourNoir.png" };
    images_["cavalierNoir"] = QPixmap{ "images/cavalierNoir.png" };
    images_["FouNoir"] = QPixmap{ "images/fouNoir.png" };
    images_["dameNoir"] = QPixmap{ "images/dameNoir.png" };
    images_["PionNoir"] = QPixmap{ "images/pionNoir.png" };

}

void Projet::paintEvent(QPaintEvent* event) {

    QPainter painter(this);

    painter.setBrush(QColor(101, 67, 33));
    painter.drawRect(0, 0, width(), height());

    

    
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0)
                    painter.setBrush(marronClair);
                else
                    painter.setBrush(marronFonce);

                painter.drawRect(j * TAILLE_CASE + TAILLE_BORDURE, i * TAILLE_CASE + TAILLE_BORDURE, TAILLE_CASE, TAILLE_CASE);
            }
        }
   
    if (ligneSelectionnee_ != -1) {
        painter.setBrush(jaune);
        painter.drawRect(colonneSelectionnee_ * TAILLE_CASE + TAILLE_BORDURE, 
            ligneSelectionnee_ * TAILLE_CASE + TAILLE_BORDURE, TAILLE_CASE, TAILLE_CASE);
    }

    for (auto& piece : echiquier_.getPieces()) {
        int x = piece->getColonne() * TAILLE_CASE + TAILLE_BORDURE + 3;
        int y = piece->getLigne() * TAILLE_CASE + TAILLE_BORDURE + 3;

        if (auto roi = dynamic_cast<Roi*>(piece.get())) {
            if (roi->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["roiBlanc"]);
            }
            else {
                painter.drawPixmap(x , y, TAILLE_PIECE, TAILLE_PIECE, images_["roiNoir"]);
            }
        }
        else if (auto cavalier = dynamic_cast<Cavalier*>(piece.get()))
            if (cavalier->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["cavalierBlanc"]);
            }
            else {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["cavalierNoir"]);
            }

        else if (auto tour = dynamic_cast<Tour*>(piece.get())) {
            if (tour->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["tourBlanc"]);
            }
            else {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["tourNoir"]);
            }
        }
        else if (auto fou = dynamic_cast<Fou*>(piece.get())) {
            if (fou->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["fouBlanc"]);
            }
            else {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["FouNoir"]);
            }
        }
        else if (auto dame = dynamic_cast<Dame*>(piece.get())) {
            if (dame->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["dameBlanc"]);
            }
            else {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["dameNoir"]);
            }
        }
        else if (auto pion = dynamic_cast<Pion*>(piece.get())) {
            if (pion->getCouleur() == Couleur::BLANC) {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["PionBlanc"]);
            }
            else {
                painter.drawPixmap(x, y, TAILLE_PIECE, TAILLE_PIECE, images_["PionNoir"]);
            }
        }


    }
    }


void Projet::mousePressEvent(QMouseEvent* click) {
    if (ligneSelectionnee_ == -1 && colonneSelectionnee_ == -1) {
        ligneSelectionnee_ = (click->position().y() - TAILLE_BORDURE - 3) / TAILLE_CASE;
        colonneSelectionnee_ = (click->position().x() - TAILLE_BORDURE - 3) / TAILLE_CASE;
        if (echiquier_.caseOccuper(ligneSelectionnee_, colonneSelectionnee_) == nullptr) {
            ligneSelectionnee_ = -1;
            colonneSelectionnee_ = -1;
            return;
        }
        update();

    }
    else {
        int nouvelleLigne = (click->position().y() - TAILLE_BORDURE - 3) / TAILLE_CASE;
        int nouvelleColonne = (click->position().x() - TAILLE_BORDURE - 3) / TAILLE_CASE;

        echiquier_.deplacerPiece(ligneSelectionnee_, colonneSelectionnee_, nouvelleLigne, nouvelleColonne);

        ligneSelectionnee_ = -1;
        colonneSelectionnee_ = -1;
    }
    mettreCaseJaune = !mettreCaseJaune;
    update();
}