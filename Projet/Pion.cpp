#include "Pion.h"


using namespace modele;

Pion::Pion(int ligne, int colonne, Couleur couleur) : Piece(ligne, colonne, couleur), premierMouvement_(true) {}


bool Pion::mouvementValide(int ligneDestination, int colonneDestination) const {
	int direction = 0;
	if (getCouleur() == Couleur::BLANC) direction = -1;

	else direction = 1;

	if (ligneDestination == getLigne() + direction && colonneDestination == getColonne()) return true;

	if (ligneDestination == getLigne() + direction * 2 && colonneDestination == getColonne()
		&& premierMouvement_) return true;

	return false;

}

void Pion::retirerDroitDeuxCases() {
	premierMouvement_ = false;
}