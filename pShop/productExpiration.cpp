#include "productExpiration.h"

productExpiration::productExpiration(string name, string type, float cost, string expiration_date) : product(name, type, cost)
{
	this->expiration_date = expiration_date;
}

string productExpiration::getProductExp()
{
	return expiration_date;
}

void productExpiration::setProductExp(string expiration_date)
{
	this->expiration_date = expiration_date;
}

productExpiration::productExpiration()
{
}

productExpiration::~productExpiration()
{
}
