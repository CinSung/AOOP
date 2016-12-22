#pragma once
#include <vector>
#include <string>
#include "Staffs.h"
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
	  MYSQL();
      MYSQL(string Username,string Password){
        username = Username;
        password = Password;
      }
	  void setUser(string user){
		username = user;
	  }
	  void setPassword(string pass){
		password = pass;
	  }
      vector <Supplier> getSupplier();
      vector <Package> getPackage();
      vector <Product> getProduct();
      vector <Staffs> getStaff();
      bool insertSQL( Supplier& );
      bool updatePackage(int PackageID,string collectorName,int oDay,int oMonth,int oYear,bool retrieved= false);
	  bool insertSQL( Package &);
      bool insertSQL(  Product &);
	  bool sendCommand(const string );
	  bool updateProduct(Product& product,int item2Add);

  //    bool insertSQL( const Staffs &);
  //    bool insertSQL( const Account &);
  //    bool insertSQL( const storeInfo &);
};