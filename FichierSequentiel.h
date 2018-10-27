/************************************************************

FichierSequentiel.h
--------------------
Desc :		G�re la lecture d'un fichier s�quentiel.
Auteur:		Micka�l DEBALME
Date :		20/01/2017
Version :	1

*************************************************************/

#pragma once

#include "Fichier.h"

class FichierSequentiel : public Fichier {

public:

	FichierSequentiel(std::string chemin, std::string nom);
	virtual ~FichierSequentiel();

	/* On donne les m�mes arguments que la m�thode lire() de Fichier pour ne pas avoir d'erreur */
	virtual std::vector<std::string> lire(int pos = 0, int nbDeCharADecouper = 0);

};
