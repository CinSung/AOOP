#include "StdAfx.h"
#include "Package.h"
#include <ctime>
#include <string.h>
using namespace std;

Package::Package(void)
{
	time_t t = time(0);
	struct tm now;
	localtime_s( &now,&t);
	InTime.Year = now.tm_year+1900;
	InTime.Month = now.tm_mon+1900;
	InTime.Day = now.tm_mday;
	long int ID = 0000000;
	retrieved = false;
}
Package::Package(long int id,unsigned int day,unsigned int month,unsigned int year,char *Name){
	strcpy(name,Name);
	ID = id;
	InTime.Year = year;
	InTime.Month = month;
	InTime.Day = day;
	retrieved = false;
}
void Package::Retrieve(char *Note)
{
	strcpy(note,Note);
	time_t t = time(0);
	struct tm now;
	localtime_s( &now,&t);
	OutTime.Year = now.tm_year+1900;
	OutTime.Month = now.tm_mon+1900;
	OutTime.Day = now.tm_mday;
	retrieved = true;
}

void Package::Retrieve(unsigned int day,unsigned int month,unsigned int year,char *Note){
	strcpy(note,Note);
	OutTime.Year = year;
	OutTime.Month = month;
	OutTime.Day = day;
	retrieved = true;
}
