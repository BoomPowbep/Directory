/************************************************************

LigneAnnuaireDirect.cpp
------------------------
Desc :		Stocke les informations d'une ligne sous forme
			de chaine de caract�res, � destination d'un fichier
			direct.
Auteur:		Micka�l DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#include "LigneAnnuaireDirect.h"

using namespace std;

LigneAnnuaireDirect::LigneAnnuaireDirect() {
	cout << "LigneAnnuaireDirect::Constructor" << endl;
}

LigneAnnuaireDirect::~LigneAnnuaireDirect() {
	cout << "LigneAnnuaireDirect::Destructor" << endl;
}

string LigneAnnuaireDirect::formaterLigne(LigneAnnuaire *params) {
	// Longueur totale d'un champ: 100 caract�res
	string output = formaterChamp(params->mNom) + formaterChamp(params->mPrenom) + formaterChamp(params->mAge) + formaterChamp(params->mTelephone);
	return output;
}

string LigneAnnuaireDirect::formaterChamp(string champAFormater) {
	/* Un champ doit �tre de 25 caract�res */
	while (champAFormater.length() < 25) {
		champAFormater += " ";
	}
	return champAFormater;
}
