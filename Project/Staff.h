#pragma once

#include <string>
using namespace std;

class Staff
{
	string name;
	string position;
	unsigned int salary;	
	public:
		Staff(){
			salary = 0;
			position = "none";
		};
		Staff(string name,string post,unsigned int salary):name(name),position(post),salary(salary){}

};