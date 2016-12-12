#include "StdAfx.h"
#include "PurchaseManage.h"
using namespace System::Windows::Forms;
using namespace System;
using namespace MySql::Data::MySqlClient;
void MarshalString ( String ^ s, string& os ) {  
   using namespace Runtime::InteropServices;  
   const char* chars =   
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();  
   os = chars;  
   Marshal::FreeHGlobal(IntPtr((void*)chars));  
}  

bool PurchaseManage::syncData(string username,string password){
<<<<<<< HEAD
	String^ user  = gcnew String (username.c_str());
	String^ pswd = gcnew String (password.c_str());
=======
	String^ user = gcnew String(username.c_str());
	String^ pswd = gcnew String(password.c_str());
>>>>>>> origin/master
	String^ sqlQuery = "select * from suppliers";
	String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+user+";password="+pswd+";database=MYSQL57";
	MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
	MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
	MySqlDataReader^ dataReader;
	
	long int id;
	int itemAmt;
	string address;
	string name;
	long int itemID;
	String ^ buffer;
	try{
		conn->Open();
		dataReader = connCmd->ExecuteReader();
		if(dataReader->HasRows){
			while(dataReader->Read()){
				id = dataReader->GetInt32(0);
				itemAmt = dataReader->GetInt32(1);
				itemID = dataReader->GetInt32(4);
				buffer = System::Convert::ToString(dataReader->GetString(2));
				MarshalString(buffer,address);
				MarshalString(System::Convert::ToString(dataReader->GetString(3)),name);
				Suppliers.push_back(Supplier(id,address,name,itemAmt,itemID));
			}
		}
	}catch(Exception ^e){
		
		MessageBox::Show(e->Message);
	}
	return true;
}

PurchaseManage::PurchaseManage(string username,string password)
{
	this->syncData(username,password);
}
PurchaseManage::PurchaseManage(void){}