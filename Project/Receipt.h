#pragma once
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class Receipt
{
	string Name;
	string Date;
	int itemID;
	int Price;
	public:
		Receipt(void);
		Receipt(string name,string date,int price,int id):Name(name),Date(date),Price(price),itemID(id){ }
		string getName(){
			return Name;
		}
		string getDate(){
			return Date;
		}
		int getPrice(){
			return Price;
		}
		int getID(){
			return itemID;
		}
};

