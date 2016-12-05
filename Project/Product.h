#pragma once
#include <string>

class Product {
	string name;
	double priceforstack;
	double priceforfew;
	double tax; // 5% is 0.05
	long int amount;
	public:
		Product(const string,const double,const double,const double,const long int);

};
