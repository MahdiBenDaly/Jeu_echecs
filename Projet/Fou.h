#pragma once

#include "Piece.h"



namespace modele {
	class Fou : public Piece {
	public:
		Fou(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;
	};
}