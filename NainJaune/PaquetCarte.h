#pragma once

#include <vector>
#include <algorithm>

#include "Carte.h"

class PaquetCarte
{
private:

	std::vector<Carte*> m_paquet;

public:

	PaquetCarte();
	~PaquetCarte();

	void randPaquet();

	Carte* getPaquet() const;

	void popPaquet();

	void setPaquet(Carte* Carte);

	int getSizePaquet();

	
};

