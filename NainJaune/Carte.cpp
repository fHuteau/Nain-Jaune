#include "Carte.h"

using namespace std;

Carte::Carte(int numero, string signe) : m_numero(numero), m_signe(signe)
{}

void color(int t, int f)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f * 16 + t);
}

void Carte::colorCarte()
{
	if (this->m_signe == "Carreau" || this->m_signe == "Coeur") {
		color(4, 15);
	}
	else {
		color(0, 15);
	}
}

void Carte::colorNormal()
{
	color(15, 0);
}

int Carte::getNumero()
{
	return m_numero;
}

string Carte::getSigne()
{
	return m_signe;
}