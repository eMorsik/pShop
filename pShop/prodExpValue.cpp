#include "prodExpValue.h"

prodExpValue::prodExpValue()
{
}

prodExpValue::~prodExpValue()
{
}

prodExpValue::prodExpValue(string name, string type, float cost, string exp_date, int value): productExpiration(name, type, cost, exp_date)
{
	this->value = value;
}

int prodExpValue::getProdExpValue()
{
	return value;
}

void prodExpValue::setProdExpValue(int value)
{
	this->value = value;
}
