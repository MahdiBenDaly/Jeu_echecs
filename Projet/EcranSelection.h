// Fichier :     EcranSelection.h
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Ecran de selection des scenarios de fin de partie.

#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
	
#include "Projet.h"

namespace vue {

	class EcranSelection : public QWidget {
		Q_OBJECT
	public:
		EcranSelection();

	private:
		void setUpUI();

		QPushButton* laBourdonnais_ = new QPushButton("La Bourdonnais vs. McDonnell, 1834");
		QPushButton* karpov_ = new QPushButton("Karpov vs. Ftacnik, 1988");
		QPushButton* kasparov_ = new QPushButton("J. Polgar vs. Kasparov, 1996");
		QPushButton* alekhine_ = new QPushButton("Alekhine vs.Capablanca, 1927");
		QPushButton* retourPageAcueil_ = new QPushButton("Page d'acueil");

		QHBoxLayout* ligneSelection1_ = new QHBoxLayout;
		QHBoxLayout* ligneSelection2_ = new QHBoxLayout;
		QHBoxLayout* ligneBoutonRetour_ = new QHBoxLayout;

		QVBoxLayout* layout_ = new QVBoxLayout;


			
	};

}

