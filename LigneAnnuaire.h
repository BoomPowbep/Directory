/************************************************************

LigneAnnuaire.h
----------------
Desc :		Stocke les informations d'une ligne (classe abstraite)
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#pragma once

#include <string>
#include <iostream>

#include "Personne.h"

class LigneAnnuaire : public Personne {

public:

	LigneAnnuaire();
	virtual ~LigneAnnuaire();

	virtual std::string formaterLigne(LigneAnnuaire *params) = 0; // La classe est abstraite

public:

	std::string mTelephone;

};
