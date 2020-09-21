#include "Jeton.h"
using namespace std;

Jeton::Jeton(int point, string nom) : o_point(point), nom(nom)
{}

int Jeton::getPoint()
{
	return o_point;
}