// Fichier :     Echiquier.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de l'echiquier.

#include "Echiquier.h"

#include "DeplacementTemporaire.h"
#include "Roi.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Dame.h"

#include <algorithm>
#include <fstream>
#include <cmath>

using namespace modele;
using namespace std;
    



Echiquier::Echiquier(const string& nomDuFichier) {

    ifstream fichier(nomDuFichier);

    string nomPiece;
    int ligne = 0;
    int colonne = 0;

    while (fichier >> nomPiece >> ligne >> colonne) {
        if (nomPiece == "roiBlanc"){
            ajouterPiece(make_unique<Roi>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "roiNoir"){
            ajouterPiece(make_unique<Roi>(ligne, colonne, Couleur::NOIR));
        }
        else if (nomPiece == "tourBlanc"){
            ajouterPiece(make_unique<Tour>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "tourNoir"){
            ajouterPiece(make_unique<Tour>(ligne, colonne, Couleur::NOIR));
        }
        else if (nomPiece == "cavalierBlanc"){
            ajouterPiece(make_unique<Cavalier>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "cavalierNoir"){
            ajouterPiece(make_unique<Cavalier>(ligne, colonne, Couleur::NOIR));
        }
        else if (nomPiece == "fouBlanc") {
            ajouterPiece(make_unique<Fou>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "fouNoir") {
            ajouterPiece(make_unique<Fou>(ligne, colonne, Couleur::NOIR));
        }
        else if (nomPiece == "dameBlanc") {
            ajouterPiece(make_unique<Dame>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "dameNoir") {
            ajouterPiece(make_unique<Dame>(ligne, colonne, Couleur::NOIR));
        }
        else if (nomPiece == "pionBlanc") {
            ajouterPiece(make_unique<Pion>(ligne, colonne, Couleur::BLANC));
        }
        else if (nomPiece == "pionNoir") {
            ajouterPiece(make_unique<Pion>(ligne, colonne, Couleur::NOIR));
        }
    }


}


void Echiquier::ajouterPiece(unique_ptr<Piece> piece) {
	pieces_.push_back(std::move(piece));
}

Piece* Echiquier::caseOccuper(int ligne, int colonne) const {
	for (const auto& piece : pieces_) {
		if (piece->getColonne() == colonne && piece->getLigne() == ligne) {
			return piece.get();
		}
	}
	return nullptr;
}

const vector<unique_ptr<Piece>>& Echiquier::getPieces() const { return pieces_; }

bool Echiquier::cheminLibreLigneDroite(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const{
    if (ligneDepart == ligneDestination) {
        if (colonneDestination > colonneDepart) {
            for (int i = colonneDepart + 1; i < colonneDestination; ++i) {
                if (caseOccuper(ligneDestination, i) != nullptr) {  
                    return false;
                }
            }
        }
        else {
            for (int i = colonneDestination + 1; i < colonneDepart; ++i) {
                if (caseOccuper(ligneDestination, i) != nullptr) {
                    return false;
                }
            }
        }
    }
    else {
        if (ligneDestination > ligneDepart) {
            for (int i = ligneDepart + 1; i < ligneDestination; ++i) {
                if (caseOccuper(i, colonneDestination) != nullptr) {
                    return false;
                }
            }
        }
        else {
            for (int i = ligneDestination + 1; i < ligneDepart; ++i) {
                if (caseOccuper(i, colonneDestination) != nullptr) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Echiquier::cheminLibrePourFou(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const {
    if (ligneDepart < ligneDestination) {
        if (colonneDepart > colonneDestination){
            for (int i = 1; i < std::abs(ligneDestination - ligneDepart) ; ++i) {
                if (caseOccuper(ligneDepart + i, colonneDepart - i)) return false;
            }
        }
        else {
            for (int i = 1; i < std::abs(ligneDestination - ligneDepart); ++i) {
                if (caseOccuper(ligneDepart + i, colonneDepart + i)) return false;
            }
        }
    }
    else {
        if (colonneDepart > colonneDestination) {
            for (int i = 1; i < std::abs(ligneDestination - ligneDepart); ++i) {
                if (caseOccuper(ligneDepart - i, colonneDepart - i)) return false;
            }
        }
        else {
            for (int i = 1; i < std::abs(ligneDestination - ligneDepart); ++i) {
                if (caseOccuper(ligneDepart - i, colonneDepart + i)) return false;
            }
        }
    }
    return true;
}


bool Echiquier::cheminLibrePourDame(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const {
    if (ligneDepart == ligneDestination || colonneDepart == colonneDestination)
        return cheminLibreLigneDroite(ligneDepart, colonneDepart, ligneDestination, colonneDestination);
    else
        return cheminLibrePourFou(ligneDepart, colonneDepart, ligneDestination, colonneDestination);
}

bool Echiquier::mouvementValidePion(Pion* pion, int ligneDestination, int colonneDestination) const {
    int colonneDepart = pion->getColonne();
    int ligneDepart = pion->getLigne();
    int direction = pion->getDirection();
    
    Piece* caseDestination = caseOccuper(ligneDestination, colonneDestination);

    Couleur couleur = pion->getCouleur();

    if (pion->mouvementValide(ligneDestination, colonneDestination) && caseDestination == nullptr) return true;

    if (ligneDepart + direction == ligneDestination && colonneDepart + 1 == colonneDestination && caseDestination != nullptr) return true;

    if (ligneDepart + direction == ligneDestination && colonneDepart - 1 == colonneDestination && caseDestination != nullptr) return true;

    return false;

}

bool Echiquier::deplacerPiece(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) {
    auto pieceCaseDebut = caseOccuper(ligneDepart, colonneDepart);
    auto pion = dynamic_cast<Pion*>(pieceCaseDebut);

    if (pieceCaseDebut == nullptr) return false;
    
    if (pion != nullptr) {
        if (!mouvementValidePion(pion, ligneDestination, colonneDestination)) return false;

        if (!cheminLibreLigneDroite(ligneDepart, colonneDepart, ligneDestination, colonneDestination)) return false;
    }
    else if (!pieceCaseDebut->mouvementValide(ligneDestination, colonneDestination)) return false;

    if ((pieceCaseDebut->getCouleur() == Couleur::BLANC && couleurABouger_ != false) || 
        (pieceCaseDebut->getCouleur() == Couleur::NOIR && couleurABouger_ != true)) return false;

    auto pieceCaseDestination = caseOccuper(ligneDestination, colonneDestination);

    if (pieceCaseDestination != nullptr && pieceCaseDestination->getCouleur() == pieceCaseDebut->getCouleur()) return false;

    if (auto tour = dynamic_cast<Tour*>(pieceCaseDebut)) {
        if (!cheminLibreLigneDroite(tour->getLigne(), tour->getColonne(), ligneDestination, colonneDestination)) return false;
    }

    if (auto fou = dynamic_cast<Fou*>(pieceCaseDebut)) {
        if (!cheminLibrePourFou(fou->getLigne(), fou->getColonne(), ligneDestination, colonneDestination)) return false;
    }

    if (auto dame = dynamic_cast<Dame*>(pieceCaseDebut)) {
        if (!cheminLibrePourDame(dame->getLigne(), dame->getColonne(), ligneDestination, colonneDestination)) return false;
    }

    unique_ptr<Piece> pieceCapturee;
    if (pieceCaseDestination != nullptr) {
        auto it = find_if(pieces_.begin(), pieces_.end(), [&](const unique_ptr<Piece>& p) {
            return p.get() == pieceCaseDestination;
            });
        pieceCapturee = std::move(*it);
        pieces_.erase(it);
    }

    DeplacementTemporaire pieceEnCase(pieceCaseDebut, ligneDestination, colonneDestination);

    if (estEnEchec(pieceCaseDebut->getCouleur())) {
        if (pieceCapturee != nullptr)
            pieces_.push_back(std::move(pieceCapturee));
        return false;
    }

    pieceEnCase.confimer();
    
    if (pion != nullptr) pion->retirerDroitDeuxCases();

    couleurABouger_ = !couleurABouger_;
    return true;
}

bool Echiquier::estEnEchec(Couleur couleur) const {
	for (auto& piece : pieces_) {
		if (auto roi = dynamic_cast<Roi*>(piece.get()); roi != nullptr && roi->getCouleur() == couleur) {
			
			int ligneRoi = roi->getLigne();
			int colonneRoi = roi->getColonne();

			for (auto& autrePiece : pieces_) {
                if (auto tour = dynamic_cast<Tour*>(autrePiece.get())) {
                    if (!cheminLibreLigneDroite(tour->getLigne(), tour->getColonne(), ligneRoi, colonneRoi)) {
                        continue;
                    }
                }
                else if (auto fou = dynamic_cast<Fou*>(autrePiece.get())) {
                    if (!cheminLibrePourFou(fou->getLigne(), fou->getColonne(), ligneRoi, colonneRoi)) {
                        continue;
                    }
                }
                else if (auto dame = dynamic_cast<Dame*>(autrePiece.get())) {
                    if (!cheminLibrePourDame(dame->getLigne(), dame->getColonne(), ligneRoi, colonneRoi)) {
                        continue;
                    }
                }


				if (autrePiece->mouvementValide(ligneRoi, colonneRoi) && autrePiece->getCouleur() != couleur) {
					return true;
				}
			}
		}
	}
	return false;
}

