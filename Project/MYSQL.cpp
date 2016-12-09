#include "StdAfx.h"
#include "MYSQL.h"
#include <vector>
using namespace System::Windows::Forms;

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
  
  //        result.push_back(Supplier(li2,str1,str2,i2,li1));
      }
    }
  }catch(Exception ^e){
//    return false;
    MessageBox::Show(e->Message);
  }
  return result;
}