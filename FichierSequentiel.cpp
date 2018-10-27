/************************************************************

FichierSequentiel.cpp
----------------------
Desc :		Gère la lecture d'un fichier séquentiel.
Auteur:		Mickaël DEBALME
Date :		20/01/2017
Version :	1

*************************************************************/

#include "FichierSequentiel.h"

using namespace std;

FichierSequentiel::FichierSequentiel(string chemin, string nom) : Fichier(chemin, nom) {
	cout << "FichierSequentiel::Constructor" << endl;
}

FichierSequentiel::~FichierSequentiel() {
	cout << "FichierSequentiel::Destructor" << endl;
}

vector<string> FichierSequentiel::lire(int pos, int nbDeCharADecouper) {
	string ligne;
	vector<string> donneesLues;

	if (mFichierLecture->is_open()) {
		// Lecture du fichier ligne par ligne
		while (getline(*mFichierLecture, ligne)) {
			donneesLues.push_back(ligne);
		}
	}

	return donneesLues;
}
