#pragma once

#include "stdafx.h"
using namespace std;

class Product
{
	int id;
	int price;
	int amount;
	string name;
	public:
		Product(void);
		Product(int ID,int Price,int Amount,string Name){
			id = ID;
			price = Price;
			amount = Amount;
			name = Name;
		}
		string getName(){ return name; }
		int getID(){ return id; }
		int getPrice(){ return price; }
		int getAmount(){ return amount; }
};

