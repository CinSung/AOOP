#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Staff
{
	string name;
	string position;
	unsigned int salary;	
public:
	Staff(void){
		salary = 0;
		name="";
		position = "none";
	}
	Staff(string _name,string _post,unsigned int _salary){
		name=_name;
		position=_post;
		salary=_salary;
	}

};