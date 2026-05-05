#pragma once

#include "Piece.h"

namespace modele {
	class Pion : public Piece {
	public:
		Pion(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;

		void retirerDroitDeuxCases();

		int getDirection() const;

	private:
		bool premierMouvement_ = false;
	};


}
