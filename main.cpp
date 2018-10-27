/************************************************************

main.cpp
---------
Desc :		Point d'entrée du programme.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#include "Annuaire.h"
#include "FichierSequentiel.h"
#include "FichierDirect.h"

using namespace std;

int main() {

#ifdef __linux__
    FichierSequentiel *f_seq = new FichierSequentiel("./", "annuaire_seq.txt");
	FichierDirect *f_dir = new FichierDirect("./", "annuaire_dir.txt");
#elif _WIN32
	/// Le chemin doit être ".\\" sur Windows
	FichierSequentiel *f_seq = new FichierSequentiel(".\\", "annuaire_seq.txt");
	FichierDirect *f_dir = new FichierDirect(".\\", "annuaire_dir.txt");
#endif

	Annuaire *monAnnuaire = new Annuaire();

	int choix(0), recommencer(0);

	do {
		do {
			#ifdef __linux__
                system("clear");
            #elif _WIN32
                system("cls");
            #endif

			cout << "Partie 1 - Fichier sequentiel" << endl;
			cout << "\tSaisir et enregistrer\t-> 1" << endl;
			cout << "\tLire un enregistrement\t-> 2" << endl;
			cout << "\tLire l'annuaire\t\t-> 3" << endl;

			cout << "\nPartie 2 - Fichier direct" << endl;
			cout << "\tSaisir et enregistrer\t-> 4" << endl;
			cout << "\tLire un enregistrement\t-> 5" << endl;

			cout << "\nQuitter\t-> 6" << endl;

			cout << "\nVotre choix : ";
			cin >> choix;

			switch (choix) {
			case 1:
				monAnnuaire->ajouterEnregistrement(f_seq, SEQUENTIEL);
				break;
			case 2:
				monAnnuaire->afficherEnregistrement(f_seq, SEQUENTIEL);
				break;
			case 3:
				monAnnuaire->afficherAnnuaire(f_seq, SEQUENTIEL);
				break;
			case 4:
				monAnnuaire->ajouterEnregistrement(f_dir, DIRECT);
				break;
			case 5:
				monAnnuaire->afficherEnregistrement(f_dir, DIRECT);
				break;
			case 6:
				break;
			}

		} while (choix > 7 || choix < 1);

		if (choix != 6) {
			cout << "\nVoulez-vous continuer ? \n\tOui\t-> 1\n\tNon\t-> 0" << endl;
			cin >> recommencer;
		}
		else
			recommencer = 0;
	} while (recommencer);

	delete f_seq;
	delete f_dir;
	delete monAnnuaire;

	return 0;
}
