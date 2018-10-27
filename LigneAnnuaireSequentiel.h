/************************************************************

LigneAnnuaireSequentiel.h
--------------------------
Desc :		Stocke les informations d'une ligne sous forme 
			de chaine de caract�res, � destination d'un fichier 
			s�quentiel.
Auteur:		Micka�l DEBALME
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
