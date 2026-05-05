// Fichier :     Tour.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe representant la tour dans le jeu d'echecs.

#pragma once

#include "Piece.h"


namespace modele {

	class Tour : public Piece {
	public:
		Tour(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;

	};
}

