
#include <time.h>
#include <windows.h>
#include <iostream>
#include <vector>

#include "Joueur.h"
#include "Plateau.h"

using namespace std;


int verifierMainJoueur(vector<Carte*> pileCarte, Joueur* joueur)
{
	int x(0);

	if (pileCarte.size() != 0) {
		for (x = 1; x < joueur->getSizeMain(); x++) {
			if (pileCarte.back()->getNumero() + 1 == joueur->getCarte(x)->getNumero()) {
				return 1;
			}
		}
		return 0;
	}
	return 1;
}

int verifierSuiteMainJoueur(vector<Carte*> pileCarte, Joueur* joueur, int carteChoisie)
{
	int x(1);

	do {
		if (joueur->getCarte(carteChoisie - x)->getNumero() == pileCarte.back()->getNumero() + 1)
			return 1;

		else if (joueur->getCarte(carteChoisie - x)->getNumero() > pileCarte.back()->getNumero() + 1)
			return 0;

		else if (joueur->getCarte(carteChoisie - x)->getNumero() == pileCarte.back()->getNumero())
			x++;
		

	} while ( x > 1);
}

void afficherPileCarte(vector<Carte*> pileCarte) {

	cout << "	Pile de carte : " << endl;

	if (pileCarte.size() == 0) {
		cout << "		vide" << endl;
	}
	else {
		pileCarte.back()->colorCarte();

		switch (pileCarte.back()->getNumero()) {
		case 7:
			if (pileCarte.back()->getSigne() == "Carreau")
				cout << "	{ 7  carreau } *" << endl;
			else
				cout << "	{ 7  " << pileCarte.back()->getSigne() << " }" << endl;

			break;
		case 10:
			if (pileCarte.back()->getSigne() == "Carreau")
				cout << "	{ 10  carreau } *" << endl;
			else
				cout << "	{ 10  " << pileCarte.back()->getSigne() << " }" << endl;

			break;
		case 11:
			if (pileCarte.back()->getSigne() == "Trefle")
				cout << "	{ Vallet  Trefle } *" << endl;
			else
				cout << "	{ Vallet  " << pileCarte.back()->getSigne() << " }" << endl;

			break;
		case 12:
			if (pileCarte.back()->getSigne() == "Pique")
				cout << "	{ Dame  Pique } *" << endl;
			else
				cout << "	{ Dame  " << pileCarte.back()->getSigne() << " }" << endl;

			break;
		case 13:
			if (pileCarte.back()->getSigne() == "Coeur")
				cout << "	{ Roi  Coeur } *" << endl;
			else
				cout << "	{ Roi  " << pileCarte.back()->getSigne() << " }" << endl;

			break;
		default:
			cout << "	{ " << pileCarte.back()->getNumero() << "  " << pileCarte.back()->getSigne() << " }" << endl;
		}
		pileCarte.back()->colorNormal();
	}
}

void afficherSansCarte(vector<Carte*> pileCarte, int i,int nbjoueur, vector<Joueur*> tabJoueur)
{
	system("cls");

	cout << "	Sans ";

	switch (pileCarte.back()->getNumero() + 1) {
	case 11:
		cout << "Vallet " << endl;
		break;
	case 12:
		cout << "Dame" << endl;
		break;
	case 13:
		cout << "Roi " << endl;
		break;
	default:
		cout << pileCarte.back()->getNumero() + 1 << endl;
	}
	if (i < nbjoueur - 1)
		cout << "	Au tour de " << tabJoueur[i + 1]->getNom() << "." << endl;
	else
		cout << "	Au tour de " << tabJoueur[0]->getNom() << "." << endl;
	system("PAUSE");
}

void verifierCarteBonus(vector<Carte*> pileCarte, Joueur* Joueur, Plateau Plateau)
{
	switch (pileCarte.back()->getNumero()) {
	case 10:
		if (pileCarte.back()->getSigne() == "Carreau")
			Plateau.gainJeton10Carreau(Joueur);
		break;
	case 11:
		if (pileCarte.back()->getSigne() == "Trefle")
			Plateau.gainJetonValTrefle(Joueur);
		break;
	case 12:
		if (pileCarte.back()->getSigne() == "Pique")
			Plateau.gainJetonDamePique(Joueur);
		break;
	case 13:
		if (pileCarte.back()->getSigne() == "Coeur")
			Plateau.gainJetonRoiCoeur(Joueur);
		break;
	case 7:
		if (pileCarte.back()->getSigne() == "Carreau")
			Plateau.gainJetonNainJaune(Joueur);
		break;
	}
}

int errorOverCarteChoisie(int carteChoisie, vector<Joueur*> tabJoueur, int i)
{
	while (carteChoisie > tabJoueur[i]->getSizeMain() - 1 || carteChoisie < 0) {
		cout << "	Vous n'avez pas choisie une carte valide. Veuillez reessayer." << endl;
		cout << "	Joueur choisi une carte : ";
		cin >> carteChoisie;
		carteChoisie--;
	}
	return carteChoisie;
}

int main()
{
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
	srand(time(NULL));

	Plateau Plateau;
	PaquetCarte* Paquet(new PaquetCarte);

	vector<Joueur*> tabJoueur, tabJoueurEnAttente;

	vector<Carte*> pileCarte;

	int i(0), x(0), nbjoueur(0), probleme(0), carteChoisie(0), partie(1), tour(0);

	cout << "Nain Jaune" << endl;
	cout << endl;

	do {
		cout << "Entrez le nombre de joueur (3 a 8 joueurs) : ";
		cin >> nbjoueur;
	} while (nbjoueur < 3 || nbjoueur > 8);

	system("cls");

	for (i = 0; i < nbjoueur; i++) {
		tabJoueur.push_back(new Joueur(i + 1));
	}
	while (partie == 1) {
		for (i = 0; i < nbjoueur; i++) {
			tabJoueur[i]->PiocheMain(Paquet, nbjoueur);
			tabJoueur[i]->RangerMain();
			tabJoueur[i]->PiocheJeton();
			if (Plateau.DistributionJetonPlateau(tabJoueur[i]) == 0) {
				tabJoueurEnAttente.push_back(tabJoueur[i]);
			}
		}
		probleme = 0;
			while (tabJoueurEnAttente.size() != 0) {
				if (Plateau.DistributionJetonPlateau(tabJoueurEnAttente[0]) == 0) {
					tabJoueurEnAttente.push_back(tabJoueurEnAttente[0]);
					tabJoueurEnAttente.erase(tabJoueurEnAttente.begin());
					probleme++;
					if (probleme == 20) {
						cout << "Probleme !!! Jeu casse !!!";
						system("PAUSE");
					}
				}
				else {
					tabJoueurEnAttente.erase(tabJoueurEnAttente.begin());
				}
			}
		
		cout << "Joueurs jouent..." << endl;
		system("PAUSE");

		partie = 0;

		while (partie == 0) {

			for (i = 0; i < nbjoueur; i++) {
				if (tour == 1)
					i--;
				else
				while (verifierMainJoueur(pileCarte, tabJoueur[i]) == 0) {
					afficherSansCarte(pileCarte, i, nbjoueur, tabJoueur);
					i++;
				}

				system("cls");
				Plateau.afficherPlateau();
				cout << endl;
				afficherPileCarte(pileCarte);

				tabJoueur[i]->afficherJeton();
				tabJoueur[i]->afficherMain();

				if (i < nbjoueur)
					cout << "	" << tabJoueur[i]->getNom() << " choisit une carte : ";
				else
					cout << "	" << tabJoueur[0]->getNom() << " choisit une carte : ";

				cin >> carteChoisie;
				carteChoisie --;
				
				carteChoisie = errorOverCarteChoisie(carteChoisie, tabJoueur, i);

				if (pileCarte.size() != 0) {
					while (tabJoueur[i]->getCarte(carteChoisie)->getNumero() != pileCarte.back()->getNumero() + 1) {
						cout << "	Vous n'avez pas choisie une carte valide. Veuillez reessayer." << endl;
						cout << "	Joueur choisi une carte : ";
						cin >> carteChoisie;
						carteChoisie--;
						carteChoisie = errorOverCarteChoisie(carteChoisie, tabJoueur, i);
					}
				}

				pileCarte.push_back(tabJoueur[i]->getCarte(carteChoisie));
				tabJoueur[i]->eraseCarte(carteChoisie);
				verifierCarteBonus(pileCarte, tabJoueur[i], Plateau);

				if (tabJoueur[i]->getSizeMain() == 0) {
					cout << tabJoueur[i]->getNom() << " a gagne la manche." << endl;
					while (partie != 1 && partie != 2) {
						cout << "Voulez-vous continuer a jouer ( 1 : refaire une manche, 2 : terminer la partie) : ";
						cin >> partie;
					}
					//i = nbjoueur + 1;
				}
				else 
					tour = verifierSuiteMainJoueur(pileCarte, tabJoueur[i], carteChoisie);
					
				if (tour == 0) {
					afficherSansCarte(pileCarte, i, nbjoueur, tabJoueur);

				}

				if (i == nbjoueur - 1)
					i = 0;
				

			}
		}


	}
}










// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
