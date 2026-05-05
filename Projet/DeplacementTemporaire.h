// Fichier :     DeplacementTemporaire.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe RAII pour deplacer temporairement une piece.

#pragma once

#include "Piece.h"
namespace modele {

	class DeplacementTemporaire {
	public:
		DeplacementTemporaire(Piece* piece, int ligneDestination, int colonneDestination);

		void confimer();

		~DeplacementTemporaire();
	private:
		Piece* piece_;
		int ancinennePositionLigne_ = 0;
		int anciennePositionColonne_ = 0;
		bool confirmer_ = false;
	};
}

