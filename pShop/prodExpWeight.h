#pragma once
#include "productExpiration.h"

class prodExpWeight: public productExpiration
{
private:
	float weight;	//вес товара в кг
public:
	prodExpWeight();
	~prodExpWeight();
	prodExpWeight(string name, string type, float cost, string exp_date, float weight);

	float getProdExpWeight();
	void setProdExpWeight(float weight);
};

