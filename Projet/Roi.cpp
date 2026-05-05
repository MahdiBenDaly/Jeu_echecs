// Fichier :     Roi.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation du roi.

#include "Roi.h"

#include <algorithm>

using namespace modele;


int Roi::nInstance_ = 0;

Roi::Roi(int ligne, int colonne, Couleur couleur) : Piece(ligne, colonne, couleur){
	if (nInstance_ == 2) {
		throw TropDeRoisException();
	}
	nInstance_++;
	return;
}

bool Roi::mouvementValide(int ligneDestination, int colonneDestination) const {
	int differenceX = abs(ligneDestination - getLigne());
	int differenceY = abs(colonneDestination - getColonne());

	if (std::max(differenceX, differenceY) == 1) {
		return true;
	}
	return false;
}

Roi::~Roi() {
	nInstance_--;
}