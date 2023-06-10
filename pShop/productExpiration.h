#pragma once
#include "product.h"

class productExpiration : public product
{
private:
	string expiration_date;		//срок годности товара

public:
	productExpiration();
	~productExpiration();
	productExpiration(string name, string type, float cost, string expiration_date);

	string getProductExp();
	void setProductExp(string expiration_date);

};

