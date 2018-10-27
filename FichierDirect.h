/************************************************************

FichierDirect.h
----------------
Desc :		Gère la lecture d'un fichier direct.
Auteur:		Mickaël DEBALME
Date :		20/01/2017
Version :	1

*************************************************************/

#pragma once

#include "Fichier.h"

class FichierDirect : public Fichier {

public:

	FichierDirect(std::string chemin, std::string nom);
	virtual ~FichierDirect();

	virtual std::vector<std::string> lire(int pos, int nbDeCharADecouper);

};
