#pragma once

#include <string>
#include <windows.h>



class Carte
{
private:
	int m_numero;
	std::string m_signe;

public:

	Carte(int numero, std::string signe);

	std::string getSigne();
	int getNumero();

	void colorCarte();
	void colorNormal();

};

