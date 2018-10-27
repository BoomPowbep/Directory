/************************************************************

Fichier.cpp
------------
Desc :		Gère l'ouverture et la fermeture des fichiers,
			ainsi que l'écriture et la lecture (classe abstraite).
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#include "Fichier.h"

using namespace std;

Fichier::Fichier(string chemin, string nom) : mNom(nom), mChemin(chemin), mNomComplet(mChemin + mNom), mFichierEcriture(NULL), mFichierLecture(NULL), mFichierOuvertEcriture(false), mFichierOuvertLecture(false) {
	cout << "Fichier::Constructor" << endl;
}

Fichier::~Fichier() {
	cout << "Fichier::Destructor" << endl;
	fermer(); // Si un fichier n'a pas été fermé
}

void Fichier::ouvrir(opening_mode mode) {

	if (mode == LECTURE) {
		mFichierLecture = new ifstream(mNomComplet.c_str()); // Ouverture du fichier en lecture

		if (mFichierLecture->is_open()) {
			mFichierOuvertLecture = true;
		}
	}
	else if (mode == ECRITURE) {
		mFichierEcriture = new ofstream(mNomComplet.c_str(), ios::app); // Ouverture du fichier en ecriture (ajout)

		if (mFichierEcriture->is_open()) {
			mFichierOuvertEcriture = true;
		}
	}
}

void Fichier::fermer() {
	if (mFichierOuvertEcriture) {
		mFichierEcriture->close();
		delete mFichierEcriture;
	}
	if (mFichierOuvertLecture) {
		mFichierLecture->close();
		delete mFichierLecture;
	}

	mFichierOuvertEcriture = false;
	mFichierOuvertLecture = false;
}


void Fichier::ecrire(std::string chaineAEcrire) {
	if (mFichierEcriture->is_open()) {
		/* Ecriture d'un enregistrement dans le fichier */
		*mFichierEcriture << chaineAEcrire;
		cout << "\nEnregistre !" << endl;
	}
}
