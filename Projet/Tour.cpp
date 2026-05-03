// Fichier :     Tour.cpp
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Implementation de la tour.

#include "Tour.h"

using namespace modele;


Tour::Tour(int ligne, int colonne, Couleur couleur): Piece(ligne, colonne,couleur){}

bool Tour::mouvementValide(int ligneDestination, int colonneDestination) const {
	if (ligneDestination == getLigne() || colonneDestination == getColonne()) {
		return true;
	}
	return false;
		
}
