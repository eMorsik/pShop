#pragma once
#include <iostream>
using namespace std;

class product
{

private:
	string name;	//������������ ������
	string type;	//��� ������
	float cost;		//��������� ������

public:
	product();
	~product();
	product(string name, string type, float cost);

	string getProductName();
	string getProductType();
	float getProductCost();

	void setProductName(string name);
	void setProductType(string type);
	void setProductCost(float price);

};