#pragma once
#include <vector>
#include <string>
#include "Staff.h"
#include "Supplier.h"
#include "Product.h"
#include "Package.h"
using namespace MySql::Data::MySqlClient;
using namespace std;
using namespace System;
class MYSQL{
  private:
    string username;
    string password;
    void MarshalString ( String ^ s, string& os ) {
  	   using namespace Runtime::InteropServices;
  	   const char* chars =
  	      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
  	   os = chars;
  	   Marshal::FreeHGlobal(IntPtr((void*)chars));
  	}
  	void MarshalString ( String ^ s, wstring& os ) {
  	   using namespace Runtime::InteropServices;
  	   const wchar_t* chars =
  	      (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
  	   os = chars;
  	   Marshal::FreeHGlobal(IntPtr((void*)chars));
  	}
    	bool security(String ^input); //prevent sql injection attack
    public:
      MYSQL(string Username,string Password){
        username = Username;
        password = Password;
      }
      vector <Supplier> getSupplier();
      vector <Package> getPackage();
      vector <Product> getProduct();
  //    vector <Staff> getStaff();
      bool insertSQL( const Supplier &);
  //    bool insertSQL( const Package &);
      bool insertSQL( const Product &);
  //    bool insertSQL( const Staff &);
  //    bool insertSQL( const Account &);
  //    bool insertSQL( const storeInfo &);
};