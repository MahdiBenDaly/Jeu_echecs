# Jeu d'Échecs - Fins de Partie

## Description
Jeu d'échecs en C++ avec interface graphique Qt, axé sur les fins de partie.
Le jeu supporte le déplacement des pièces, la détection d'échec, et la capture de pièces.

## Technologies
- C++ 20
- Qt 6 (Widgets)
- Visual Studio 2022

## Scénarios inclus
- La Bourdonnais vs. McDonnell, 1834
- Karpov vs. Ftacnik, 1988
- J. Polgar vs. Kasparov, 1996
- Alekhine vs. Capablanca, 1927
- plus a venir...

## Comment lancer
1. Ouvrir `Projet.sln` dans Visual Studio 2022
2. Installer Qt 6 via Qt Visual Studio Tools
3. Compiler et lancer!

## Sources des images
Images des pièces : https://commons.wikimedia.org/wiki/Category:SVG_chess_pieces

## Architecture
- `modele/` : Logique du jeu (Piece, Roi, Tour, Cavalier, Fou, Dame, Echiquier)
- `vue/` : Interface graphique Qt (Projet, EcranAccueil, EcranSelection)
