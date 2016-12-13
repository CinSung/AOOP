#pragma once

#include "stdafx.h"
using namespace std;

class Product
{
	int id;
	double priceForStack;
	double priceForFew;
	int amount;
	double tax;
	string name;
	public:
		Product(void);
		Product(int ID,int Price,int Amount,string Name){
			id = ID;
			priceForFew = Price;
			amount = Amount;
			name = Name;
		}
		Product(string name,double priceStack,double priceFew,double Tax,int Amount,int ID ):
			name(name),
			priceForStack(priceStack),
			priceForFew(priceFew),
			id(ID),
			amount(Amount),
			tax(Tax){}
		string getName(){ return name; }
		int getID(){ return id; }
		double getPriceFew(){ return priceForFew; }
		double getTax(){ return tax; }
		double getPriceStack(){ return priceForStack; }
		int getAmount(){ return amount; }
};

