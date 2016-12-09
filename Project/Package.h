#pragma once

#include "stdafx.h"
using namespace std;

class Package{
	long int ID;
	struct{
		unsigned int Month;
		unsigned int Day;
		int Year;
	}InTime,OutTime;
	bool retrieved;
	string name;
	string note;
public:
	Package(void);
	Package(long int,unsigned int,unsigned int,unsigned int,string = "");
	Package(long int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,string = "");
	long int getID(){ return ID; }
	unsigned int rDay(){ return InTime.Day; }
	unsigned int rMonth(){ return InTime.Month; }
	unsigned int rYear(){ return InTime.Year; }
	unsigned int oDay(){ return OutTime.Day; }
	unsigned int oMonth(){ return OutTime.Month; }
	unsigned int oYear(){ return OutTime.Year; }
	string getNote(){ return note; }
	string getName(){ return name; }
	bool getStatus(){ return retrieved; }

	void Retrieve(string Note = "");
	void Retrieve(unsigned int,unsigned int,unsigned int,string = "");

};

