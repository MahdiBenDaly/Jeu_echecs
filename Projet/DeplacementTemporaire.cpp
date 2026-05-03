// Fichier :     DeplacementTemporaire.cpp
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Implementation du deplacement temporaire RAII.

#include "DeplacementTemporaire.h"

using namespace modele;

DeplacementTemporaire::DeplacementTemporaire(Piece* piece, int ligneDestination, int colonneDestination): 
	piece_(piece), ancinennePositionLigne_(piece->getLigne()), anciennePositionColonne_(piece_->getColonne()){
	
	piece->setPosition(ligneDestination, colonneDestination);
}

void DeplacementTemporaire::confimer() {
	confirmer_ = true;
}

DeplacementTemporaire::~DeplacementTemporaire() {
	if (confirmer_ == true) {
		return;
	}
	piece_->setPosition(ancinennePositionLigne_, anciennePositionColonne_);
}

