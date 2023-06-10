#include "prodExpWeight.h"

prodExpWeight::prodExpWeight()
{
}

prodExpWeight::~prodExpWeight()
{
}

prodExpWeight::prodExpWeight(string name, string type, float cost, string exp_date, float weight): productExpiration(name, type, cost, exp_date)
{
	this->weight = weight;
}

float prodExpWeight::getProdExpWeight()
{
	return weight;
}

void prodExpWeight::setProdExpWeight(float weight)
{
	this->weight = weight;
}
