#pragma once
#include "Supplier.h"
#include "stdafx.h"
using namespace std;

class PurchaseManage
{
	vector <Supplier> Suppliers;
	bool syncData(string username,string password);

	public:
		PurchaseManage(void);
		PurchaseManage(string username,string password);
		vector <Supplier> getSupplierList(){ return Suppliers; }
};

