// Fichier :     Piece.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de la classe de base Piece.

#include "Piece.h"

modele::Piece::Piece(int ligne, int colonne, Couleur couleur): couleur_(couleur) {
	if (ligne < 0 || colonne < 0) {
		ligne_ = -1;
		colonne_ = -1;
		return;
	}
	ligne_ = ligne;
	colonne_ = colonne;
}

modele::Piece::~Piece() = default;

int modele::Piece::getColonne() const { return colonne_; }

int modele::Piece::getLigne() const { return ligne_; }

modele::Couleur modele::Piece::getCouleur() const { return couleur_; }

void modele::Piece::setPosition(int ligne, int colonne) {
	ligne_ = ligne;
	colonne_ = colonne;
}




