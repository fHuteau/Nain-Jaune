#include "Plateau.h"

using namespace std;


Plateau::Plateau() : o_DixCarreau(), o_ValetTrefle(0), o_DamePique(NULL), o_RoiCoeur(), o_SeptCarreau()
{}

int Plateau::DistributionJetonPlateau(Joueur* joueur)
{
	int i(0), x(0);
	Jeton* jeton;
	jeton = joueur->getJeton();
	if (jeton->getPoint() > 1) {
		while (x <= 5) {
			if (this->RemboursementJeton(1, jeton->getPoint(), joueur, x) == 0) {
				x++;
			}
			if (x == 6) {
				return 0;
			}
		}
		
	}

	this->o_DixCarreau.push_back(jeton);
	
	joueur->popJeton();
	jeton = NULL;

	for (i = 0; i < 2; i++) {

		jeton = joueur->getJeton();
	
		if (jeton->getPoint() > 1) {
			while (x <= 5) {
				if (this->RemboursementJeton(1, jeton->getPoint(), joueur, x) == 0) {
					x++;
				}
				if (x == 6) {
					return 0;
				}
			}
			i = 2;
		}
		this->o_ValetTrefle.push_back(jeton);

		joueur->popJeton();
	}

	for (i = 0; i < 3; i++) {

		jeton = joueur->getJeton();
		
		if (jeton->getPoint() > 1) {
			while (x <= 5) {
				if (this->RemboursementJeton(1, jeton->getPoint(), joueur, x) == 0) {
					x++;
				}
				if (x == 6) {
					return 0;
				}
			}
			i = 3;
		}
		this->o_DamePique.push_back(jeton);

		joueur->popJeton();
	}
	for (i = 0; i < 4; i++) {

		jeton = joueur->getJeton();
		
		if (jeton->getPoint() > 1) {
			while (x <= 5) {
				if (this->RemboursementJeton(1, jeton->getPoint(), joueur, x) == 0) {
					x++;
				}
				if (x == 6) {
					return 0;
				}
			}
			i = 4;
		}
		this->o_RoiCoeur.push_back(jeton);
		
		joueur->popJeton();
	}
	for (i = 0; i < 5; i++) {

		jeton =joueur->getJeton();

		if (jeton->getPoint() > 1) {
			while (x <= 5) {
				if (this->RemboursementJeton(1, jeton->getPoint(), joueur, x) == 0) {
					x++;
				}
				if (x == 6) {
					return 0;
				}
			}
			i = 5;
		}
		this->o_SeptCarreau.push_back(jeton);

		joueur->popJeton();
	}
	return 1;
}


int Plateau::RemboursementJeton(int pointAttendu, int pointEnvoye, Joueur* joueur,int casePlateau)
{
	int i(0);
	vector<Jeton*> remboursement;

	/*if (pointAttendu == 1) {
		if (pointEnvoye == 5) {*/
	if (casePlateau == 1) {
		while ((pointEnvoye - pointAttendu) > 0 || i < o_DixCarreau.size()) {
			if (o_DixCarreau[i]->getPoint() < pointEnvoye && o_DixCarreau[i]->getPoint() <= (pointEnvoye - pointAttendu)) {
				remboursement.push_back(o_DixCarreau[i]);
				o_DixCarreau.erase(o_DixCarreau.begin() + i);
				i -= 1;
				pointEnvoye = pointEnvoye - o_DixCarreau[i]->getPoint();
			
			}
			i++;
		}
	}
	else if (casePlateau == 2) {
		while ((pointEnvoye - pointAttendu) > 0 || i < o_ValetTrefle.size()) {
			if (o_ValetTrefle[i]->getPoint() < pointEnvoye && o_ValetTrefle[i]->getPoint() <= (pointEnvoye - pointAttendu)) {
				remboursement.push_back(o_ValetTrefle[i]);
				o_ValetTrefle.erase(o_ValetTrefle.begin() + i);
				i -= 1;
				pointEnvoye = pointEnvoye - o_ValetTrefle[i]->getPoint();

			}
			i++;
		}
	}
	else if (casePlateau == 3) {
		while ((pointEnvoye - pointAttendu) > 0 || i < o_DamePique.size()) {
			if (o_DamePique[i]->getPoint() < pointEnvoye && o_DamePique[i]->getPoint() <= (pointEnvoye - pointAttendu)) {
				remboursement.push_back(o_DamePique[i]);
				o_DamePique.erase(o_DamePique.begin() + i);
				i -= 1;
				pointEnvoye = pointEnvoye - o_DamePique[i]->getPoint();

			}
			i++;
		}
	}
	else if (casePlateau == 4) {
		while ((pointEnvoye - pointAttendu) > 0 || i < o_RoiCoeur.size()) {
			if (o_RoiCoeur[i]->getPoint() < pointEnvoye && o_RoiCoeur[i]->getPoint() <= (pointEnvoye - pointAttendu)) {
				remboursement.push_back(o_RoiCoeur[i]);
				o_RoiCoeur.erase(o_RoiCoeur.begin() + i);
				i -= 1;
				pointEnvoye = pointEnvoye - o_RoiCoeur[i]->getPoint();

			}
			i++;
		}
	}
	else if (casePlateau == 5) {
		while ((pointEnvoye - pointAttendu) > 0 || i < o_SeptCarreau.size()) {
			if (o_SeptCarreau[i]->getPoint() < pointEnvoye && o_SeptCarreau[i]->getPoint() <= (pointEnvoye - pointAttendu)) {
				remboursement.push_back(o_SeptCarreau[i]);
				o_SeptCarreau.erase(o_SeptCarreau.begin() + i);
				i -= 1;
				pointEnvoye = pointEnvoye - o_SeptCarreau[i]->getPoint();

			}
			i++;
		}
	}
	if ((pointEnvoye - pointAttendu) == 0) {
		while (remboursement.size() > 0) {
			joueur->setJeton(remboursement.back());
			remboursement.pop_back();
		}
		return 1;
	}
	else {
		return 0;
	}
}
/*
		else if (pointEnvoye == 10) {

		}

	}
	else if (pointAttendu == 2) {
		if (pointEnvoye == 5) {

		}
		else if (pointEnvoye == 10) {

		}
	}
	else if (pointAttendu == 3) {
		if (pointEnvoye == 5) {

		}
		else if (pointEnvoye == 10) {

		}
	}
	else if (pointAttendu == 4) {
		if (pointEnvoye == 5) {

		}
		else if (pointEnvoye == 10) {

		}
	}
	else if (pointAttendu == 5) {
		if (pointEnvoye == 5) {

		}
		else if (pointEnvoye == 10) {

		}
	}
}*/


void Plateau::gainJeton10Carreau(Joueur* joueur)
{
	while (!o_DixCarreau.empty()) {
		joueur->setJeton(o_DixCarreau.back());
		o_DixCarreau.pop_back();
	}
	o_DixCarreau.shrink_to_fit();
}

void Plateau::gainJetonValTrefle(Joueur* joueur)
{
	while (!o_ValetTrefle.empty()) {
		joueur->setJeton(o_ValetTrefle.back());
		o_ValetTrefle.pop_back();
	}
	o_ValetTrefle.shrink_to_fit();
}

void Plateau::gainJetonDamePique(Joueur* joueur)
{
	while (!o_DamePique.empty()) {
		joueur->setJeton(o_DamePique.back());
		o_DamePique.pop_back();
	}
	o_DamePique.shrink_to_fit();
}

void Plateau::gainJetonRoiCoeur(Joueur* joueur)
{
	while (!this->o_RoiCoeur.empty()) {
		joueur->setJeton(o_RoiCoeur.back());
		this->o_RoiCoeur.pop_back();
	}
	this->o_RoiCoeur.shrink_to_fit();
}

void Plateau::gainJetonNainJaune(Joueur* joueur)
{
	while (!this->o_SeptCarreau.empty()) {
		joueur->setJeton(o_SeptCarreau.back());
		this->o_SeptCarreau.pop_back();
	}
	this->o_SeptCarreau.shrink_to_fit();
}

void Plateau::afficherPlateau()
{
	cout << endl;
	cout << "		-------------------------------------------" << endl;
	cout << "		|10 Carreau :   |           |Roi Coeur :  |" << endl;
	cout << "		|               |-----------|             |" << endl;
	cout << "		|"<<this->totalCaseJeton("10") << " points       |7 Carreau :| " << this->totalCaseJeton("Roi") << " points   |" << endl;
	cout << "		|               |" << this->totalCaseJeton("7") << " points  |             |" << endl;
	cout << "		|---------------|           |-------------|" << endl;
	cout << "		|Vallet Trefle :|           |Dame Pique : |" << endl;
	cout << "		|" << this->totalCaseJeton("Vallet") << " points       |-----------|" << this->totalCaseJeton("Dame") << " points     |" << endl;
	cout << "		|               |           |             |" << endl;
	cout << "		|               |           |             |" << endl;
	cout << "		-------------------------------------------" << endl;
	
}


int Plateau::totalCaseJeton(string place)
{
	int i(0), x(0);
	if (place == "10") {
		for (i = 0; i < this->o_DixCarreau.size(); i++) {
			x = x + this->o_DixCarreau[i]->getPoint();
		}
		return x;
	}
	else if(place == "Vallet"){
		for (i = 0; i < this->o_ValetTrefle.size(); i++) {
			x = x + this->o_ValetTrefle[i]->getPoint();
		}
		return x;
	}
	else if (place == "Dame") {
		for (i = 0; i < this->o_DamePique.size(); i++) {
			x = x + this->o_DamePique[i]->getPoint();
		}
		return x;
	}
	else if (place == "Roi") {
		for (i = 0; i < this->o_RoiCoeur.size(); i++) {
			x = x + this->o_RoiCoeur[i]->getPoint();
		}
		return x;
	}
	else if (place == "7") {
		for (i = 0; i < this->o_SeptCarreau.size(); i++) {
			x = x + this->o_SeptCarreau[i]->getPoint();
		}
		return x;
	}
}