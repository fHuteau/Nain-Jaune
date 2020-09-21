#pragma once
#include <string>

class Jeton
{
private:
	int o_point;
	std::string nom;

public:
	Jeton(int point, std::string nom);
	int getPoint();
	};
