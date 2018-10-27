/************************************************************

LigneAnnuaireSequentiel.cpp
----------------------------
Desc :		Stocke les informations d'une ligne sous forme
			de chaine de caractères, à destination d'un fichier
			séquentiel.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#include "LigneAnnuaireSequentiel.h"

using namespace std;

LigneAnnuaireSequentiel::LigneAnnuaireSequentiel() {
	cout << "LigneAnnuaireSequentiel::Constructor" << endl;
}

LigneAnnuaireSequentiel::~LigneAnnuaireSequentiel() {
	cout << "LigneAnnuaireSequentiel::Destructor" << endl;
}

string LigneAnnuaireSequentiel::formaterLigne(LigneAnnuaire *params) {
	string delimiteur(";");

	return params->mNom + delimiteur + params->mPrenom + delimiteur + params->mAge + delimiteur + params->mTelephone + "\n";
}
