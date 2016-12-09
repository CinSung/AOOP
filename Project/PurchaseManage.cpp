#include "StdAfx.h"
#include "PurchaseManage.h"
#include "MYSQL.h"

using namespace std;
using namespace System::Windows::Forms;
using namespace System;
using namespace MySql::Data::MySqlClient;

bool PurchaseManage::syncData(string username,string password){

	return true;
}

PurchaseManage::PurchaseManage(string username,string password)
{
	MYSQL sqlhelper(username,password);
	Suppliers = sqlhelper.getSupplier();
//	this->syncData(username,password);
}
PurchaseManage::PurchaseManage(void){}