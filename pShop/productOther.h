#pragma once
#include "product.h"


class productOther : public product
{
private:
	int value;	//���-�� ������ � ������
public:
	productOther();
	~productOther();
	productOther(string name, string type, float cost, int value);

	int getProdValue();
	void setProdValue(int value);
};

