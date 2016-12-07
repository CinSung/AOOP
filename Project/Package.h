#pragma once

#include "stdafx.h"

class Package
{
	long int ID;
	struct{
		unsigned int Month;
		unsigned int Day;
		int Year;
	}InTime,OutTime;
	bool retrieved;
	char name[50];
	char note[500];
public:
	Package(void);
	Package(long int,unsigned int,unsigned int,unsigned int,char *);
	unsigned int rDay(){ return InTime.Day; }
	unsigned int rMonth(){ return InTime.Month; }
	unsigned int rYear(){ return InTime.Year; }
	unsigned int oDay(){ return OutTime.Day; }
	unsigned int oMonth(){ return OutTime.Month; }
	unsigned int oYear(){ return OutTime.Year; }
	char *getNote(){ return note; }
	char *getName(){ return name; }
	bool getStatus(){ return status; }

	void Retrieve(char *Note = NULL);
	void Retrieve(unsigned int,unsigned int,unsigned int,char * = NULL);

};

