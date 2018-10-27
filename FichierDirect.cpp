/************************************************************

FichierDirect.cpp
------------------
Desc :		G�re la lecture d'un fichier direct.
Auteur:		Micka�l DEBALME
Date :		20/01/2017
Version :	1

*************************************************************/

#include "FichierDirect.h"

using namespace std;

FichierDirect::FichierDirect(string chemin, string nom) : Fichier(chemin, nom) {
	cout << "FichierDirect::Constructor" << endl;
}

FichierDirect::~FichierDirect() {
	cout << "FichierDirect::Destructor" << endl;
}

vector<string> FichierDirect::lire(int pos, int nbDeCharADecouper) {
	vector<string> enregistrement(1);
	char tempChar(' ');

	if (mFichierLecture->is_open()) {
		/* On positionne le curseur � la position pos * nbDeCharADecouper - nbDeCharADecouper */
		mFichierLecture->seekg(pos * nbDeCharADecouper - nbDeCharADecouper, ios::beg);

		/* Lecture de l'enregistrement */
		for (int i(0); i < nbDeCharADecouper; i++) {
			mFichierLecture->get(tempChar); // R�cup�ration d'un caract�re
			enregistrement[0] += tempChar; // Ajout � l'enregistrement
		}

		return enregistrement;
	}

	return vector<string>();
}
