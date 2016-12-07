#pragma once
#include "Product.h"
#include "stdafx.h"
using namespace std;

class Supplier
{
	long int ID;
	int itemAmount;
	string address;
	string companyName;
	Product *items;
public:
	Supplier(void){
		ID = 0;
		address = "";
		companyName = "";
		itemAmount = 0;
	}
	Supplier(long int id,string addr,string name,int itemAmt,Product *product = NULL){
		itemAmount = itemAmt;
		ID = id;
		address=addr;
		companyName=name;
		items = new Product [itemAmt];
		for(int i=0;i < itemAmt;i++){
			items[i] = product[i];
		}
	}
	Supplier(const Supplier &p){
		itemAmount = p.itemAmount;
		ID = p.ID;
		address = p.address;
		companyName = p.companyName;
		items = new Product [itemAmount];
		for(int i=0;i<itemAmount;i++){
			items[i] = p.items[i];
		}
	}
	~Supplier(){
		delete [] items;
	}
	long int getID(){ return ID; }
	int getItemAmount(){ return itemAmount; }
	string getAddress(){ return address; }
	string getCompanyName(){ return companyName; }
	Product * getItems(){ return items; }

};

