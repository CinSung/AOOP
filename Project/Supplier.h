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
	long int itemID;
public:
	Supplier(void){
		ID = 0;
		address = "";
		companyName = "";
		itemAmount = 0;
	}
	Supplier(long int id,string addr,string name,int itemAmt,long int itemid ){
		itemAmount = itemAmt;
		ID = id;
		address=addr;
		companyName=name;
		itemID = itemid;
	}
	Supplier(const Supplier &p){
		itemAmount = p.itemAmount;
		ID = p.ID;
		address = p.address;
		companyName = p.companyName;
		itemID = p.itemID;
	}
	void setID(long int id){ ID = id;}
	void setItems(long int itemid ){ itemID = itemid; }  
	void setCompany(string name ){ companyName = name; }
	void setAddress( string addr ){ address = addr; }
	void setItemAmount( int itemAmt ){ itemAmount = itemAmt; }

	long int getID(){ return ID; }
	int getItemAmount(){ return itemAmount; }
	string getAddress(){ return address; }
	string getCompanyName(){ return companyName; }
	long int getItemID(){ return itemID; }

};

