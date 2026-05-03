// Fichier :     Echiquier.h
// Auteurs :     Mahdi Ben Daly et Adel Chaouki
// Date :        21 avril 2026
// Description : Classe representant l'echiquier du jeu d'echecs.

#pragma once

#include "Roi.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Dame.h"


#include <vector>
#include <memory>
#include <string>

namespace modele {
	
	class Echiquier {
	public:
		Echiquier(const std::string& nomDuFichier);

		void ajouterPiece(std::unique_ptr<Piece> piece);
		
		const std::vector<std::unique_ptr<Piece>>& getPieces() const;

		modele::Piece* caseOccuper(int ligne, int colonne) const;

		bool deplacerPiece(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination);


	private:
		bool estEnEchec(Couleur couleur) const;

		bool cheminLibrePourTour(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;
		bool cheminLibrePourFou(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;
		bool cheminLibrePourDame(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;


	private:
		std::vector<std::unique_ptr<Piece>> pieces_;
		bool couleurABouger_ = false; //false->blanc, true->noir
	};
}
