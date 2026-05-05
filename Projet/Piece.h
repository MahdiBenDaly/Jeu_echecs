// Fichier :     Piece.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Classe de base abstraite pour les pieces du jeu d'echecs.

#pragma once

namespace modele {

	enum class Couleur {
		BLANC,
		NOIR
	};

	class Piece {
	public:
		Piece(int ligne, int colonne, Couleur couleur);

		virtual ~Piece();

		int getLigne() const;
		int getColonne() const;
		Couleur getCouleur() const;

		void setPosition(int ligne, int colonne);

		virtual bool mouvementValide(int LigneDestination, int colonneDestination) const = 0;


	private:
		int ligne_ = 0;
		int colonne_ = 0;
		Couleur couleur_;
	};

}

