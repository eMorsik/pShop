#include "product.h"

product::product()
{

}

product::~product()
{

}

product::product(string name, string type, float cost)
{
    this->name = name;
    this->type = type;
    this->cost = cost;
}

string product::getProductName()
{
    return name;
}

string product::getProductType()
{
    return type;
}

float product::getProductCost()
{
    return cost;
}

void product::setProductName(string name)
{
    this->name = name;
}

void product::setProductType(string type)
{
    this->type = type;
}

void product::setProductCost(float price)
{
    this->cost = price;
}



