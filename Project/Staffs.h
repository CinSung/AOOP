#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Staffs
{
	string name;
	string position;
	unsigned int salary;	
public:
	Staffs(void){
		salary = 0;
		name="";
		position = "none";
	}
	Staffs(string _name,string _post,unsigned int _salary){
		name=_name;
		position=_post;
		salary=_salary;
	}

	string & getname(){return name;}
	string & getposition(){return position;}
	unsigned int & getsalary(){return salary;}

};
