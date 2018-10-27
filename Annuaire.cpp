/************************************************************

Annuaire.cpp
-------------
Desc :		Permet d'ajouter et de consulter une ligne, et
			d'afficher l'annuaire complet.
Auteur:		Mickaël DEBALME
Date :		15/01/2017
Version :	1

*************************************************************/

#include "Annuaire.h"

using namespace std;

Annuaire::Annuaire() {
	cout << "Annuaire::Constructor" << endl;

	mLigneAnnuaireSequentiel = new LigneAnnuaireSequentiel();
	mLigneAnnuaireDirect = new LigneAnnuaireDirect();
	mListeEnregistrements = vector<string>();
	mNomTemp = "";
	mPrenomTemp = "";
	mAgeTemp = "";
	mTelephoneTemp = "";
}

Annuaire::~Annuaire() {
	delete mLigneAnnuaireSequentiel;
	delete mLigneAnnuaireDirect;
	cout << "Annuaire::Destructor" << endl;
}

void Annuaire::ajouterEnregistrement(Fichier *f, type type) {
	/* Saisie des champs */
	cin.ignore();
	system("clear");
	cout << "Saisir un enregistrement : \n---------------------------" << endl;
	cout << "Saisir le nom [20 char. max] : ";
	getline(cin, mNomTemp);
	cout << "Saisir le prenom [20 char. max] : ";
	getline(cin, mPrenomTemp);
	cout << "Saisir l'age : ";
	getline(cin, mAgeTemp);
	cout << "Saisir le numero de telephone [format xx-xx-xx-xx-xx] : ";
	getline(cin, mTelephoneTemp);

	cout << "\nVoulez-vous enregistrer ? \n\tOui\t-> 1\n\tNon\t-> 0" << endl;
	int choix(0);
	cin >> choix;

	if (choix) {

		/* Enregistrement dans le fichier */
		f->ouvrir(ECRITURE);

		if (type == SEQUENTIEL) {
			/* Affectation des valeurs à l'objet mLigneAnnuaireSequentiel */
			mLigneAnnuaireSequentiel->mNom = mNomTemp;
			mLigneAnnuaireSequentiel->mPrenom = mPrenomTemp;
			mLigneAnnuaireSequentiel->mAge = mAgeTemp;
			mLigneAnnuaireSequentiel->mTelephone = mTelephoneTemp;

			string ligneAnnuaireSequentielFormatee = mLigneAnnuaireSequentiel->formaterLigne(mLigneAnnuaireSequentiel); // Création d'une ligne formatée pour le stockage séquentiel
			f->ecrire(ligneAnnuaireSequentielFormatee); // Ecriture de la ligne dans le fichier
		}
		else if (type == DIRECT) {
			/* Affectation des valeurs à l'objet mLigneAnnuaireSequentiel */
			mLigneAnnuaireDirect->mNom = mNomTemp;
			mLigneAnnuaireDirect->mPrenom = mPrenomTemp;
			mLigneAnnuaireDirect->mAge = mAgeTemp;
			mLigneAnnuaireDirect->mTelephone = mTelephoneTemp;

			string ligneAnnuaireDirectFormatee = mLigneAnnuaireDirect->formaterLigne(mLigneAnnuaireDirect);
			f->ecrire(ligneAnnuaireDirectFormatee);
		}

		f->fermer();
	}
}

void Annuaire::afficherEnregistrement(Fichier *f, type type) {

	system("clear");
	cout << "Recherche : \n------------" << endl;

	mListeEnregistrements.clear(); // Effacement du tableau (utile si il y a une deuxième sollicitation)

	f->ouvrir(LECTURE); // Ouverture du fichier en lecture

	if (type == SEQUENTIEL) {

		cout << "Saisir un nom : ";
		string keyword;
		cin >> keyword;

		mListeEnregistrements = f->lire(); // Lecture du fichier, stockage dans mListeEnregistrements

		vector<string> match_enreg = chercherEnregistrement(keyword, SEQUENTIEL); // On cherche si il y a des enregistrements correspondants, et on les stocke

		if (!match_enreg.empty()) {

			if(match_enreg.size() > 1)
				cout << "\n" << match_enreg.size() << " enregistrements trouves : \n----------------------------" << endl;
			else
				cout << "\n1 enregistrement trouve : \n--------------------------" << endl;

			cout << "Nom\t\t\tPrenom\t\tAge\tNumero de telephone" << endl;
			cout << "---\t\t\t------\t\t---\t-------------------" << endl;

			/* Affichage des enregistrements trouvés ligne par ligne */
			for (unsigned int i(0); i < match_enreg.size(); i++) {
				string delimiteur(";"), temp(""), precedent("");
				size_t pos(0); // Position dans l'enregistrement

				/* Extraction et affichage de chaque champ */
				for (int j(0); j < 4; j++) {
					pos = match_enreg[i].find(delimiteur); // On cherche la position du premier délimiteur
					temp = match_enreg[i].substr(0, pos); // On récupère la chaîne contenue entre la position 0 et le délimiteur
					match_enreg[i].erase(0, pos + 1); // On efface la partie traitée et le délimiteur qui suit

					// Affichage
					afficherListeEnregistrementsFormatee(j, &temp, &precedent);
				}
			}
		}
		else {
			cout << "\nAucun enregistrement trouve !" << endl;
		}
	}
	else if (type == DIRECT) {

		cout << "\nEntrer le numero de la ligne d'annuaire : ";
		int numLigne(0);
		cin >> numLigne;

		mListeEnregistrements = f->lire(numLigne, 100); // On récupère les 100 caractères de l'enregistrement

		vector<string> chaineDecoupee = decouperChaineDirect(mListeEnregistrements); // On découpe la chaîne en 4 éléments

		afficherEnregistrementDirect(chaineDecoupee); // On affiche le résultat
	}

	f->fermer();
}

vector<string> Annuaire::decouperChaineDirect(vector<string> chaineADecouper) {

	vector<string> chaineDecoupee(4);

	chaineDecoupee[0] = chaineADecouper[0].substr(0, 25);
	chaineDecoupee[1] = chaineADecouper[0].substr(25, 25);
	chaineDecoupee[2] = chaineADecouper[0].substr(50, 25);
	chaineDecoupee[3] = chaineADecouper[0].substr(75, 25);

	return chaineDecoupee;
}

vector<string> Annuaire::chercherEnregistrement(string const& keyword, type type) {
	string delimiteur(";"); // Délimiteur dans le fichier de stockage
	size_t pos(0); // Position dans l'enregistrement
	vector<string> matching_enreg;

	/* On parcoure l'annuaire */
	for (unsigned int i(0); i < mListeEnregistrements.size(); i++) {
		pos = mListeEnregistrements[i].find(delimiteur); // On cherche la position du premier délimiteur de l'enregistrement actuel

		/* Si le nom correspond au nom recherché */
		if (mListeEnregistrements[i].substr(0, pos) == keyword) {
			matching_enreg.push_back(mListeEnregistrements[i]);
		}
	}

	if (matching_enreg.size() > 0) {
		return matching_enreg; // On renvoie les enregistrements correspondants
	}
	else {
		// Si rien n'a été trouvé, on renvoie un tableau vide
		return vector<string>();
	}
}

void Annuaire::afficherAnnuaire(Fichier *f, type type) {

	mListeEnregistrements.clear(); // Effacement du tableau (utile si il y a une deuxième sollicitation)

	/****************************************************/
	f->ouvrir(LECTURE); // Ouverture du fichier en lecture

	mListeEnregistrements = f->lire(); // Lecture du fichier, stockage dans mListeEnregistrements

	system("clear");

	cout << "Liste des enregistrements : \n----------------------------" << endl;
	cout << "Nom\t\t\tPrenom\t\tAge\tNumero de telephone" << endl;
	cout << "---\t\t\t------\t\t---\t-------------------" << endl;

	if (type == SEQUENTIEL) {
		/* Affichage des enregistrements ligne par ligne */
		for (unsigned int i(0); i < mListeEnregistrements.size(); i++) {
			string delimiteur(";"), temp(""), precedent("");
			size_t pos(0); // Position dans l'enregistrement

			/* Extraction et affichage de chaque champ */
			for (int j(0); j < 4; j++) {
				pos = mListeEnregistrements[i].find(delimiteur); // On cherche la position du premier délimiteur
				temp = mListeEnregistrements[i].substr(0, pos); // On récupère la chaîne contenue entre la position 0 et le délimiteur
				mListeEnregistrements[i].erase(0, pos + 1); // On efface la partie traitée et le délimiteur qui suit

				// Affichage
				afficherListeEnregistrementsFormatee(j, &temp, &precedent);
			}
		}
	}

	f->fermer();
	/****************************************************/
}

void Annuaire::afficherListeEnregistrementsFormatee(int j, string *temp, string *precedent) {
	switch (j) {
	case 0:
		cout << *temp;
		break;
	case 1:
		// Si le nom est supérieur à 8 lettres, on réduit le nombre de tabulations
		if (precedent->length() > 8) { cout << "\t\t" << *temp; }
		else { cout << "\t\t\t" << *temp; }
		break;
	case 2:
		// Si le prénom est supérieur à 7 lettres, on réduit le nombre de tabulations
		if (precedent->length() > 7) { cout << "\t" << *temp; }
		else { cout << "\t\t" << *temp; }
		break;
	case 3:
		cout << "\t" << *temp << endl;
		break;
	}

	*precedent = *temp;
}

void Annuaire::afficherEnregistrementDirect(vector<string> enregistrement) {
	system("clear");
	cout << "Afficher un enregistrement : \n-----------------------------" << endl;
	cout << "Nom : " << enregistrement[0] << "\nPrenom : " << enregistrement[1] << "\nAge : " << enregistrement[2] << "\nTelephone : " << enregistrement[3] << endl;
}
