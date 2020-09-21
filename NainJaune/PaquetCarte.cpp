#include "PaquetCarte.h"

using namespace std;

PaquetCarte::PaquetCarte()
{
	int i(0);
	for (i = 1; i < 14; i++) {
			this->m_paquet.push_back(new Carte(i, "Carreau"));
			this->m_paquet.push_back(new Carte(i, "Trefle"));
			this->m_paquet.push_back(new Carte(i, "Pique"));
			this->m_paquet.push_back(new Carte(i, "Coeur"));
	}
	randPaquet();
}

void PaquetCarte::randPaquet() 
{
	random_shuffle(this->m_paquet.begin(), this->m_paquet.end());
}

Carte* PaquetCarte::getPaquet() const
{
	return this->m_paquet.back();
}


void PaquetCarte::popPaquet()
{
	this->m_paquet.pop_back();
}

void PaquetCarte::setPaquet(Carte* Carte)
{
	this->m_paquet.push_back(Carte);
}

int PaquetCarte::getSizePaquet()
{
	return m_paquet.size();
}

PaquetCarte::~PaquetCarte()
{
	int i(0);

	for (i = 0; i < this->m_paquet.size(); i++) {
		delete this->m_paquet[i];
	}

}
