#pragma once
#include <string>
#include <iostream>
#include <vector>


#include "PaquetCarte.h"
#include "Jeton.h"

class Joueur
{
private:
	std::string o_nom;
	int o_position;
	std::vector<Carte*> o_mainCarte;
	std::vector<Jeton*> o_mainJeton;

public: 
	Joueur(int position);

	void PiocheMain(PaquetCarte* Paquet, int nbJoueur);

	void PiocheJeton();

	void RangerMain();

	void afficherMain();

	void afficherJeton();

	Carte* choixSuiteCarte();

	Jeton* getJeton();
	
	Carte* getCarte(int carteChoisie);

	std::string getNom();

	size_t getSizeMain();

	int getTotalJeton();

	/*Jeton* getJeton2();
	Jeton* getJeton3();
	Jeton* getJeton4();
	Jeton* getJeton5();*/

	void popJeton();

	void eraseCarte(int carteChoisie);

	void setJeton(Jeton* jeton);

};

