#include "productOther.h"

productOther::productOther()
{
}

productOther::~productOther()
{
}

productOther::productOther(string name, string type, float cost, int value) : product(name, type, cost)
{
	this->value = value;
}

int productOther::getProdValue()
{
	return value;
}

void productOther::setProdValue(int value)
{
	this->value = value;
}
