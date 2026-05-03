// Fichier :     Cavalier.h
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Classe representant le cavalier dans le jeu d'echecs.

#pragma once

#include "Piece.h"

namespace modele {

	class Cavalier : public Piece {
	public:
		Cavalier(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDesination) const override;

	};
}

