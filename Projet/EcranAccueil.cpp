// Fichier :     EcranAccueil.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de l'ecran d'accueil.

#include "EcranAccueil.h"

#include "Projet.h"
#include "EcranSelection.h"

using namespace vue;

EcranAccueil::EcranAccueil() {
    setUpUI();
}

void EcranAccueil::setUpUI() {
    setWindowTitle("Echecs");
    setWindowIcon(QIcon("images/roiBlanc.png"));
    setFixedSize(800, 400);

    setStyleSheet("background-color: rgb(40, 24, 10);");

    QString styleBouton = "background-color: rgb(101, 67, 33);"
        "color: white;"
        "font-size: 16px;"
        "border-radius: 8px;"
        "padding: 10px;";

    QLabel* imageRoi = new QLabel;

    QPixmap imageRoiBlanc("images/roiBlanc.png");

    imageRoi->setPixmap(imageRoiBlanc);

    imageRoi->setAlignment(Qt::AlignCenter);

    boutonPartieNormale_->setFixedSize(300, 50);
    boutonFinDePartie_->setFixedSize(300, 50);
    boutonFermer_->setFixedSize(300, 50);

    boutonPartieNormale_->setStyleSheet(styleBouton);
    boutonFinDePartie_->setStyleSheet(styleBouton);
    boutonFermer_->setStyleSheet(styleBouton);

    layout_->addSpacing(20);
    layout_->addWidget(imageRoi);
    layout_->addSpacing(30);
    layout_->addWidget(boutonPartieNormale_, 0, Qt::AlignCenter);
    layout_->addWidget(boutonFinDePartie_, 0, Qt::AlignCenter);
    layout_->addSpacing(10);
    layout_->addWidget(boutonFermer_, 0, Qt::AlignCenter);
    layout_->addSpacing(20);

    setLayout(layout_);

    QObject::connect(boutonFermer_, &QPushButton::clicked, this, &EcranAccueil::close);

    QObject::connect(boutonPartieNormale_, &QPushButton::clicked, [=]() {
        this->close();

        Projet* echequier = new Projet("scenarios/classique.txt");

        echequier->show();
        });

    QObject::connect(boutonFinDePartie_, &QPushButton::clicked, [=]() {
        this->close();

        EcranSelection* ecranSelection = new EcranSelection();

        ecranSelection->show();
        });
}