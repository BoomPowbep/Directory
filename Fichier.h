/************************************************************

Fichier.h
----------
Desc :		Gère l'ouverture et la fermeture des fichiers, 
			ainsi que l'écriture et la lecture (classe abstraite).
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

enum opening_mode { LECTURE, ECRITURE };

class Fichier {

public:

	Fichier(std::string chemin, std::string nom);
	virtual ~Fichier();

	void ouvrir(opening_mode mode);
	void fermer();
	void ecrire(std::string chaineAEcrire);

	virtual std::vector<std::string> lire(int pos = 0, int nbDeCharADecouper = 0) = 0; // Classe abstraite

protected:

	std::ofstream *mFichierEcriture;
	std::ifstream *mFichierLecture;
	bool mFichierOuvertEcriture;
	bool mFichierOuvertLecture;
	std::string mNom;
	std::string mChemin;
	std::string mNomComplet;

};
