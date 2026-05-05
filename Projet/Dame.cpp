// Fichier :     Dame.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de la dame.

#include "Dame.h"

#include <cmath>

using namespace modele;

Dame::Dame(int ligne, int colonne, Couleur couleur) : Piece(ligne,colonne,couleur) {}

bool Dame::mouvementValide(int ligneDestination, int colonneDestination) const {
	bool condition1 = (ligneDestination == getLigne() || colonneDestination == getColonne());
	bool condition2 = (std::abs(ligneDestination - getLigne()) == std::abs(colonneDestination - getColonne()));

	return (condition1 || condition2);
}
