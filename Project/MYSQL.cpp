#include "StdAfx.h"
#include "MYSQL.h"
#include <vector>
using namespace System::Windows::Forms;
bool MYSQL::insertSQL(Supplier &supplier){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  String^ compName = gcnew String(supplier.getCompanyName().c_str());
  String^ address = gcnew String(supplier.getAddress().c_str());
  String^ sqlQuery = "insert into suppliers(id,itemAmount,address,companyName, productID) values (" + System::Convert::ToString(supplier.getID())+ ","+ System::Convert::ToString(supplier.getItemAmount()) + ",'"+ address + "','"+
  compName + "',"+
  System::Convert::ToString(supplier.getItemID()) + ");";
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  return true;
}

bool MYSQL::insertSQL( Package &package){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  String^ name = gcnew String(package.getName().c_str());
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);

  String ^ retrieved;
  if(package.getStatus())
    retrieved = "1";
  else
    retrieved = "0";
  String^ sqlQuery = "insert into packages(id,oday,omonth,oyear,iday,imonth,iyear, name,retrieved) values (" + 
  System::Convert::ToString(package.getID()) + ","+
  System::Convert::ToString(package.oDay()) + ","+
  System::Convert::ToString(package.oMonth()) + ","+
  System::Convert::ToString(package.oYear()) + ","+
  System::Convert::ToString(package.rDay()) + ","+
  System::Convert::ToString(package.rMonth()) + ","+
  System::Convert::ToString(package.rYear()) + ",'"+
  name + "',"+
  retrieved+ ");";
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  return true;
}


bool MYSQL::insertSQL( Product& product){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  String^ prodName = gcnew String(product.getName().c_str());
  String^ sqlQuery = "insert into packages(name,priceforfew,priceforstack,tax,amount,id) values ('" + \
  prodName+ "',"+ 
  System::Convert::ToString(product.getPriceFew()) + ",'"+ 
  System::Convert::ToString(product.getPriceStack()) + "','"+
  System::Convert::ToString(product.getTax()) + "',"+
  System::Convert::ToString(product.getAmount()) + ");";
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  return true;
}
bool MYSQL::sendCommand(const string conn){
	String^ sqlCommand = gcnew String(conn.c_str());
	String ^Username = gcnew String(username.c_str());
	String^ Password = gcnew String(password.c_str());
	String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
	MySqlConnection ^connect; 
	MySqlCommand ^cmd;     
	MySqlDataReader ^reader;
	//connectstr = "Network Address="+server+";"+"Persist Security Info=no;"+"User Name="+userID+";"+"Password="+password+";";
	connect = gcnew MySqlConnection( connectionInfo );
	try			
	{ 
		connect->Open();
		cmd = gcnew MySqlCommand( sqlCommand , connect );
		reader = cmd->ExecuteReader();
	 }
	catch( Exception ^ex )
	{ 
		//System::Windows::Forms::DialogResult result;
		//result = MessageBox::Show( ex->ToString() );
		connect->Close();
		delete cmd;
		return false;
	}
	return true;
			 
}

vector <Supplier> MYSQL::getSupplier(){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ sqlQuery = "select * from suppliers";
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  MySqlDataReader^ dataReader;
  vector <Supplier> result;
  long int li1,li2;
  int i2;
  string str1,str2;
  try{
    conn->Open();
    dataReader = connCmd->ExecuteReader();
    if(dataReader->HasRows){
      while(dataReader->Read()){
          li2 = dataReader->GetInt32(0); //id
          i2 = dataReader->GetInt32(1); //itemAmt
          li1= dataReader->GetInt32(4); //itemID
          MarshalString(System::Convert::ToString(dataReader->GetString(2)),str1); //address
          MarshalString(System::Convert::ToString(dataReader->GetString(3)),str2); //name
          result.push_back(Supplier(li2,str1,str2,i2,li1));
      }
    }
  }catch(Exception ^e){
//    return false;
    MessageBox::Show(e->Message);
  }
  return result;
}

vector <Product> MYSQL::getProduct(){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ sqlQuery = "select * from products";
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  MySqlDataReader^ dataReader;
  vector <Product> result;
  long int li1,li2;
  double d1,d2,d3;
  string str1;
  try{
    conn->Open();
    dataReader = connCmd->ExecuteReader();
    if(dataReader->HasRows){
      while(dataReader->Read()){
        MarshalString(System::Convert::ToString(dataReader->GetString(0)),str1);//name
        d1 = dataReader->GetDouble(1); //priceforstack
        d2 = dataReader->GetDouble(2); //priceforfew
        d3 = dataReader->GetDouble(3); //tax
        li1 = dataReader->GetInt32(4); //amount
        li2 = dataReader->GetInt32(5); //id
        result.push_back(Product(str1,d1,d2,d3,li1,li2));
      }
    }
  }catch(Exception ^e){
//    return false;
    MessageBox::Show(e->Message);
  }
  return result;
}

vector <Package> MYSQL::getPackage(){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ sqlQuery = "select * from packages";
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  MySqlDataReader^ dataReader;
  vector <Package> result;
  long int id;
  int oday,omonth,oyear;
  int iday,imonth,iyear;
  string name;
  try{
    conn->Open();
    dataReader = connCmd->ExecuteReader();
    if(dataReader->HasRows){
      while(dataReader->Read()){
          id = dataReader->GetInt32(0); //id
          oday = dataReader->GetInt32(1); //itemAmt
          omonth = dataReader->GetInt32(2); //itemID
          oyear = dataReader->GetInt32(3);
          iday = dataReader->GetInt32(4); //itemAmt
          imonth = dataReader->GetInt32(5); //itemID
          iyear = dataReader->GetInt32(6);
          MarshalString(System::Convert::ToString(dataReader->GetString(7)),name); //address
          result.push_back(Package(id,oday,omonth,oyear,iday,imonth,iyear,name));
      }
    }
  }catch(Exception ^e){
//    return false;
    MessageBox::Show(e->Message);
  }
  return result;
}

vector <Staff> MYSQL::getStaff(){
  String ^Username = gcnew String(username.c_str());
  String^ Password = gcnew String(password.c_str());
  String^ sqlQuery = "select * from staff";
  String^ connectionInfo = "datasource=theblackcat102.com; port=3306;username="+Username+";password="+Password+";database=MYSQL57";
  MySqlConnection^ conn = gcnew MySqlConnection(connectionInfo);
  MySqlCommand^ connCmd = gcnew MySqlCommand(sqlQuery,conn);
  MySqlDataReader^ dataReader;
  vector <Staff> result;
  long int salary;
  string name,position;
  try{
    conn->Open();
    dataReader = connCmd->ExecuteReader();
    if(dataReader->HasRows){
      while(dataReader->Read()){
          MarshalString(System::Convert::ToString(dataReader->GetString(0)),name);
          MarshalString(System::Convert::ToString(dataReader->GetString(1)),position);
          salary = dataReader->GetInt32(2);
          result.push_back(Staff(name,position,salary));
      }
    }
  }catch(Exception ^e){
//    return false;
    MessageBox::Show(e->Message);
  }
  return result;
}
