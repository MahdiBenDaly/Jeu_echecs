#pragma once

#include "Piece.h"

namespace modele {
	class Dame : public Piece {
	public:
		Dame(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;
	};
}
