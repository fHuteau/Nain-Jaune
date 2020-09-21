#include "Joueur.h"
using namespace std;




Joueur::Joueur(int position) : o_position(position)
{
	cout << "Entrez le nom du joueur " << position << " : ";
	cin >> this->o_nom;

	system("cls");

}


void Joueur::PiocheMain(PaquetCarte* Paquet, int nbJoueur)
{
	int i(0);

	switch (nbJoueur) {
	case 3:
		while (this->o_mainCarte.size() < 15) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 15) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");
		}
		
		break;
	case 4:
		while (this->o_mainCarte.size() < 12) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 12) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");

		}
		break;
	case 5:
		while (this->o_mainCarte.size() < 9) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 9) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");

		}
		break;
	case 6:
		while (this->o_mainCarte.size() < 8) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 8) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");

		}
		break;
	case 7:
		while (this->o_mainCarte.size() < 7) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 7) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");

		}
		break;
	case 8:
		while (this->o_mainCarte.size() < 6) {
			this->o_mainCarte.push_back(Paquet->getPaquet());
			Paquet->popPaquet();
		}
		if (this->o_mainCarte.size() > 6) {
			cout << "ERROR OVERMAIN" << endl;
			system("PAUSE");

		}
		break;
	default:
		cout << "ERROR OVERJOUEUR" << endl;
		system("PAUSE");

	}
	cout << "Pioche..." << endl;

}

void Joueur::PiocheJeton()
{
	int i(0);
	for (i = 0; i < 5; i++) {
		this->o_mainJeton.push_back(new Jeton(10, this->o_nom));
	}
	for (i = 0; i < 10; i++) {
		this->o_mainJeton.push_back(new Jeton(5, this->o_nom));
	}
	for (i = 0; i < 20; i++) {
		this->o_mainJeton.push_back(new Jeton(1, this->o_nom));
	}
	cout << "Distribution des jetons..." << endl;

}

void Joueur::RangerMain()
{
	int x(0), i(0);
	vector<Carte*> rangement;

	do {
		i = 0;
		for ( x = 0; x < this->o_mainCarte.size() - 1; x++) {
			if (this->o_mainCarte[x]->getNumero() < this->o_mainCarte[x + 1]->getNumero()) {
				rangement.push_back(this->o_mainCarte[x]);
				this->o_mainCarte.erase(this->o_mainCarte.begin() + x);
				x--;

			}
		}
		if (rangement.size() > 0) {
			for (x = 0; x < (rangement.size() - 1); x++) {
				if (rangement[x]->getNumero() < rangement[x + 1]->getNumero()) {
					this->o_mainCarte.push_back(rangement[x]);
					rangement.erase(rangement.begin() + x);
					x--;
				}

			}
		}
		if (rangement.size() > 0) {
			this->o_mainCarte.push_back(rangement.back());
			rangement.erase(rangement.begin() + rangement.size() - 1);
			i++;
		}
	} while (i != 0);

	cout << "Main range" << endl;

}

void Joueur::afficherMain()
{
	int x(0);	 
	for (x; x < this->o_mainCarte.size(); x++) {
		this->o_mainCarte[x]->colorCarte();

		switch (this->o_mainCarte[x]->getNumero()) {
		case 7:
			if (this->o_mainCarte[x]->getSigne() == "Carreau")
				cout <<"	" << x + 1 << " : { 7  carreau } *" << endl;
			else
				cout << "	" << x + 1 << " : { 7  " << this->o_mainCarte[x]->getSigne() << " }" << endl;

			break;
		case 10:
			if (this->o_mainCarte[x]->getSigne() == "Carreau")
				cout << "	" << x + 1 << " : { 10  carreau } *" << endl;
			else
				cout << "	" << x + 1 << " : { 10  " << this->o_mainCarte[x]->getSigne() << " }" << endl;

			break;
		case 11:
			if (this->o_mainCarte[x]->getSigne() == "Trefle")
				cout << "	" << x + 1 << " : { Vallet  Trefle } *" << endl;
			else
				cout << "	" << x + 1 << " : { Vallet  " << this->o_mainCarte[x]->getSigne() << " }" << endl;

			break;
		case 12:
			if (this->o_mainCarte[x]->getSigne() == "Pique")
				cout << "	" << x + 1 << " : { Dame  Pique } *" << endl;
			else
				cout << "	" << x + 1 << " : { Dame  " << this->o_mainCarte[x]->getSigne() << " }" << endl;

			break;
		case 13:
			if (this->o_mainCarte[x]->getSigne() == "Coeur")
				cout << "	" << x + 1 << " : { Roi  Coeur } *" << endl;
			else
				cout << "	" << x + 1 << " : { Roi  " << this->o_mainCarte[x]->getSigne() << " }" << endl;

			break;
		default:
			cout << "	" << x + 1 << " : { " << this->o_mainCarte[x]->getNumero() << "  " << this->o_mainCarte[x]->getSigne() << " }" << endl;
		}
		this->o_mainCarte[x]->colorNormal();
		
	}
}

void Joueur::afficherJeton()
{
	cout << endl;
	cout << "	Vous avez " << this->getTotalJeton() << " points" << endl;
}

/*switch (nbjoueur) {
	case 3 :
		Joueur Joueur1(1), Joueur2(2), Joueur3(3);
}*/


/*Carte* Joueur::choixSuiteCarte()
{
	for (unsigned x = 0; x < this->o_mainCarte.size()-1; x++) {
		 if(this->o_mainCarte[x] = )
	}
}*/

Carte* Joueur::getCarte(int carteChoisie) 
{
	return this->o_mainCarte[carteChoisie];
}

Jeton* Joueur::getJeton()
{
	return this->o_mainJeton.back();
}

size_t Joueur::getSizeMain()
{
	return this->o_mainCarte.size();
}

string Joueur::getNom()
{
	return this->o_nom;
}

int Joueur::getTotalJeton()
{
	int i(0), x(0);
	for (i = 0;i < this->o_mainJeton.size();i++) {
		x = x + this->o_mainJeton[i]->getPoint();
		
	}
	return x;
}



/*

Jeton* Joueur::getJeton1(Plateau* plateau)
{
	int i(0), x(1);
	for (i = 0; i < o_mainJeton.size(); i++) {
		if (o_mainJeton[i]->getPoint() == 1) {
			return o_mainJeton[i];
		}
		else if (o_mainJeton[i]->getPoint() == 5) {
			while (x <= 5) {
				if (plateau->RemboursementJeton(1, 5, this, x) == 1) {
					return o_mainJeton[i];
				}
				else {
					x++;
				}
				if (x == 6) {
					return NULL;
				}
			}
		}
		else if (o_mainJeton[i]->getPoint() == 10) {
			while (x <= 5) {
				if (plateau->RemboursementJeton(1, 10, this, x) == 1) {
					return o_mainJeton[i];
				}
				else {
					x++;
				}
			}
		}
	}
}

Jeton* Joueur::getJeton2()
{
	int i(0);
	for (i = 0; i < o_mainJeton.size(); i++) {
		if (o_mainJeton[i]->getPoint() == 1) {
			return o_mainJeton[i];
		}
		else if (o_mainJeton[i]->getPoint() == 5) {

		}
		else if (o_mainJeton[i]->getPoint() == 10) {

		}
	}
	return this->o_mainJeton.back();
}

Jeton* Joueur::getJeton3(Plateau* plateau)
{
	int i(0);
	for (i = 0; i < o_mainJeton.size(); i++) {
		if (o_mainJeton[i]->getPoint() == 1) {
			return o_mainJeton[i];
		}
		else if (o_mainJeton[i]->getPoint() == 5) {

		}
		else if (o_mainJeton[i]->getPoint() == 10) {

		}
	}
	return this->o_mainJeton.back();
}

Jeton* Joueur::getJeton4(Plateau* plateau)
{
	int i(0);
	for (i = 0; i < o_mainJeton.size(); i++) {
		if (o_mainJeton[i]->getPoint() == 1) {
			return o_mainJeton[i];
		}
		else if (o_mainJeton[i]->getPoint() == 5) {

		}
		else if (o_mainJeton[i]->getPoint() == 10) {

		}
	}
	return this->o_mainJeton.back();
}

Jeton* Joueur::getJeton5(Plateau* plateau)
{
	int i(0);
	for (i = 0; i < o_mainJeton.size(); i++) {
		if (o_mainJeton[i]->getPoint() == 1) {
			return o_mainJeton[i];
		}
		else if (o_mainJeton[i]->getPoint() == 5) {

		}
		else if (o_mainJeton[i]->getPoint() == 10) {

		}
	}
	return this->o_mainJeton.back();
}*/


void Joueur::popJeton()
{
	this->o_mainJeton.pop_back();
}

void Joueur::eraseCarte(int carteChoisie)
{
	this->o_mainCarte.erase(this->o_mainCarte.begin() + carteChoisie);
}


void Joueur::setJeton(Jeton* jeton)
{
	this->o_mainJeton.push_back(jeton);
}