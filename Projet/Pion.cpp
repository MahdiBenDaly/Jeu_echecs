#include "Pion.h"


using namespace modele;

Pion::Pion(int ligne, int colonne, Couleur couleur) : Piece(ligne, colonne, couleur), premierMouvement_(true) {}

int Pion::getDirection() const {
	if (getCouleur() == Couleur::BLANC) return -1;

	else return 1;
}

bool Pion::mouvementValide(int ligneDestination, int colonneDestination) const {
	int direction = getDirection();

	if (ligneDestination == getLigne() + direction && colonneDestination == getColonne()) return true;

	if (ligneDestination == getLigne() + direction * 2 && colonneDestination == getColonne()
		&& premierMouvement_) return true;

	return false;

}

void Pion::retirerDroitDeuxCases() {
	premierMouvement_ = false;
}