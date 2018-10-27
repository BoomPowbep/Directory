/************************************************************

LigneAnnuaireSequentiel.h
--------------------------
Desc :		Stocke les informations d'une ligne sous forme 
			de chaine de caractères, à destination d'un fichier 
			séquentiel.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#pragma once

#include "LigneAnnuaire.h"

class LigneAnnuaireSequentiel : public LigneAnnuaire {

public:

	LigneAnnuaireSequentiel();
	virtual ~LigneAnnuaireSequentiel();

	virtual std::string formaterLigne(LigneAnnuaire *params);

};
