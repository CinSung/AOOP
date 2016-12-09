#pragma once

#include "stdafx.h"
using namespace std;

class Product
{
	long int id;
	double priceforfew;
	double priceforstack;
	double tax;
	long int amount;
	string name;
	public:
		Product(void);
		Product(string Name,double PriceStack,double PriceFew,double Tax,long int Amt,long int ID){
			id = ID;
			priceforfew = PriceFew;
			amount = Amt;
			priceforstack = PriceStack;
			tax = Tax;
			name = Name;
		}
		string getName(){ return name; }
		int getID(){ return id; }
		double getPriceFew(){ return priceforfew; }
		double getPriceStack(){ return priceforstack; }
		double getTax(){ return tax; }
		int getAmount(){ return amount; }
};

