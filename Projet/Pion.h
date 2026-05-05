// Fichier :     Pion.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe representant le pion dans le jeu d'echecs.

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
