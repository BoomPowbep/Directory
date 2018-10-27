/************************************************************

Personne.h
-----------
Desc :		Stocke les informations sur une personne.
Auteur:		Mickaël DEBALME
Date :		20/01/2017
Version :	1

*************************************************************/

#pragma once

#include <string>
#include <iostream>

class Personne {

public:

	Personne();
	~Personne();

	std::string mNom;
	std::string mPrenom;
	std::string mAge;

};
