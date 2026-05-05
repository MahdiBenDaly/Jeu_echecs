// Fichier :     EcranSelection.cpp
// Auteurs :     Mahdi Ben Daly
// Date :        21 avril 2026
// Description : Implementation de l'ecran de selection.

#include "EcranSelection.h"

#include "EcranAccueil.h"

using namespace vue;

void EcranSelection::setUpUI() {
    setWindowTitle("Echecs");
    setWindowIcon(QIcon("images/roiBlanc.png"));
    setFixedSize(800, 400);

    setStyleSheet("background-color: rgb(40, 24, 10);");

    QString styleBouton = "background-color: rgb(101, 67, 33);"
        "color: white;"
        "font-size: 16px;"
        "border-radius: 8px;"
        "padding: 10px;";

    laBourdonnais_->setFixedSize(300, 50);
    karpov_->setFixedSize(300, 50);;
    kasparov_->setFixedSize(300, 50);
    alekhine_->setFixedSize(300, 50);
    retourPageAcueil_->setFixedSize(145, 35);

    laBourdonnais_->setStyleSheet(styleBouton);
    karpov_->setStyleSheet(styleBouton);
    kasparov_->setStyleSheet(styleBouton);
    alekhine_->setStyleSheet(styleBouton);
    retourPageAcueil_->setStyleSheet(styleBouton);

    ligneSelection1_->addWidget(laBourdonnais_);
    ligneSelection1_->addSpacing(20);
    ligneSelection1_->addWidget(karpov_);

    ligneSelection2_->addWidget(kasparov_);
    ligneSelection2_->addSpacing(20);
    ligneSelection2_->addWidget(alekhine_);

    ligneBoutonRetour_->addWidget(retourPageAcueil_,0, Qt::AlignLeft);

    layout_->addLayout(ligneSelection1_);
    layout_->addLayout(ligneSelection2_);
    layout_->addLayout(ligneBoutonRetour_);

    setLayout(layout_);

    QObject::connect(laBourdonnais_, &QPushButton::clicked, [=]() {
        this->close();

        Projet* projet = new Projet("scenarios/laBourdonnais.txt");

        projet->show();
        });

    QObject::connect(karpov_, &QPushButton::clicked, [=]() {
        this->close();

        Projet* projet = new Projet("scenarios/karpov.txt");

        projet->show();
        });

    QObject::connect(kasparov_, &QPushButton::clicked, [=]() {
        this->close();

        Projet* projet = new Projet("scenarios/kasparov.txt");

        projet->show();
        });

    QObject::connect(alekhine_, &QPushButton::clicked, [=]() {
        this->close();

        Projet* projet = new Projet("scenarios/Alekhine.txt");

        projet->show();
        });

    QObject::connect(retourPageAcueil_, &QPushButton::clicked, [=]() {
        this->close();

        EcranAccueil* ecranAccuel = new EcranAccueil;

        ecranAccuel->show();
        });
}   

EcranSelection::EcranSelection() {
    setUpUI();
}
