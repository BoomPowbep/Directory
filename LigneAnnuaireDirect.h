/************************************************************

LigneAnnuaireDirect.h
----------------------
Desc :		Stocke les informations d'une ligne sous forme
			de chaine de caractères, à destination d'un fichier
			direct.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#pragma once

#include "LigneAnnuaire.h"

class LigneAnnuaireDirect : public LigneAnnuaire {

public:

	LigneAnnuaireDirect();
	virtual ~LigneAnnuaireDirect();

	virtual std::string formaterLigne(LigneAnnuaire *params);

private:

	std::string formaterChamp(std::string champAFormater);

};
#pragma once
