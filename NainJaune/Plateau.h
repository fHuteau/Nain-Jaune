#pragma once

#include <vector>
#include "Joueur.h"

class Plateau
{
private:
	std::vector<Jeton*> o_DixCarreau;
	std::vector<Jeton*> o_ValetTrefle;
	std::vector<Jeton*> o_DamePique;
	std::vector<Jeton*> o_RoiCoeur;
	std::vector<Jeton*> o_SeptCarreau;

public:
	Plateau();

	int DistributionJetonPlateau(Joueur* joueur);

	int RemboursementJeton(int pointAttandu, int pointEnvoye, Joueur* joueur, int casePlateau);

	void afficherPlateau();

	int totalCaseJeton(std::string place);

	//void gainJeton(std::string signeCarte, int numCarte, Joueur* joueur);
	
	void gainJeton10Carreau(Joueur* joueur);
	void gainJetonValTrefle(Joueur* joueur);
	void gainJetonDamePique(Joueur* joueur);
	void gainJetonRoiCoeur(Joueur* joueur);
	void gainJetonNainJaune(Joueur* joueur);
};

