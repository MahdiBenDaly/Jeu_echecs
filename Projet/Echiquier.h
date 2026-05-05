// Fichier :     Echiquier.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe representant l'echiquier du jeu d'echecs.

#pragma once

#include "Piece.h"
#include "Pion.h"


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
		bool estEnEchec(Couleur couleur) const;

	private:
		

		bool mouvementValidePion(Pion* pion, int ligneDestination, int colonneDestination) const;

		bool cheminLibreLigneDroite(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;
		bool cheminLibrePourFou(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;
		bool cheminLibrePourDame(int ligneDepart, int colonneDepart, int ligneDestination, int colonneDestination) const;


	private:
		std::vector<std::unique_ptr<Piece>> pieces_;
		bool couleurABouger_ = false; //false->blanc, true->noir
	};
}
