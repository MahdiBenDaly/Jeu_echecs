// Fichier :     Roi.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe representant le roi dans le jeu d'echecs.

#pragma once

#include "Piece.h"

#include <exception>

namespace modele {

	class TropDeRoisException : public std::exception {
	public:
		const char* what() const noexcept override {
			return "Trop de roi on etait instanciee";
		}

	};

	class Roi : public Piece {
	public:
		Roi(int ligne, int colonne, Couleur couleur);

		bool mouvementValide(int ligneDestination, int colonneDestination) const override;

		~Roi() override;


	private:
		static int nInstance_;
	};
}

