// Fichier :     Fou.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation du fou.

#include "Fou.h"

using namespace modele;

#include <cmath>

modele::Fou::Fou(int ligne, int colonne, Couleur couleur) : Piece(ligne, colonne, couleur) {}

bool Fou::mouvementValide(int ligneDestination, int colonneDestination) const {
	return (std::abs(ligneDestination - getLigne()) == std::abs(colonneDestination - getColonne()));
}