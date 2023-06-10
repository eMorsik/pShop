#pragma once
#include "productExpiration.h"

class prodExpValue: public productExpiration
{
private:
	int value;	//кол-во товара в штуках
public:
	prodExpValue();
	~prodExpValue();
	prodExpValue(string name, string type, float cost, string exp_date, int value);

	int getProdExpValue();
	void setProdExpValue(int value);
};

