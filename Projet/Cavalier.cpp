// Fichier :     Cavalier.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation du cavalier.

#include "Cavalier.h"

#include <cmath>

using namespace modele;

Cavalier::Cavalier(int ligne, int colonne, Couleur couleur) : Piece(ligne, colonne, couleur){}

bool Cavalier::mouvementValide(int ligneDestination, int colonneDesination) const {
	int differenceX = std::abs(ligneDestination - getLigne());
	int differenceY = std::abs(colonneDesination - getColonne());

	if ((differenceX * differenceY) == 2) {
		return true;
	}
	return false;
}