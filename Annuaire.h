/************************************************************

Annuaire.h
------------
Desc :		Permet d'ajouter et de consulter une ligne, et
			d'afficher l'annuaire complet.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#pragma once

#include "LigneAnnuaireSequentiel.h"
#include "LigneAnnuaireDirect.h"
#include "FichierSequentiel.h"
#include "FichierDirect.h"

#include <iostream>
#include <vector>
#include <string>

enum type { SEQUENTIEL, DIRECT };

class Annuaire {

public:

	Annuaire();
	~Annuaire();

	void ajouterEnregistrement(Fichier *f, type type);
	void afficherEnregistrement(Fichier *f, type type);
	void afficherAnnuaire(Fichier *f, type type);

private:

	std::vector<std::string> decouperChaineDirect(std::vector<std::string> chaineADecouper);
	std::vector<std::string> chercherEnregistrement(std::string const& keyword, type type);
	void afficherListeEnregistrementsFormatee(int j, std::string *temp, std::string *precedent);
	void afficherEnregistrementDirect(std::vector<std::string> enregistrement);

private:

	LigneAnnuaireSequentiel *mLigneAnnuaireSequentiel;
	LigneAnnuaireDirect *mLigneAnnuaireDirect;
	std::vector<std::string> mListeEnregistrements;

	std::string mNomTemp;
	std::string mPrenomTemp;
	std::string mAgeTemp;
	std::string mTelephoneTemp;

};
