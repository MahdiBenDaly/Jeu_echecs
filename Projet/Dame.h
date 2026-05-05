// Fichier :     Dame.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe representant la dame dans le jeu d'echecs.

#pragma once

#include "Piece.h"

namespace modele {
	class Dame : public Piece {
	public:
		Dame(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;
	};
}
