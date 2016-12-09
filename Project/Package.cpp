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
Package::Package(long int id,unsigned int day,unsigned int month,unsigned int year,string Name){
	name = Name;
	ID = id;
	InTime.Year = year;
	InTime.Month = month;
	InTime.Day = day;
	retrieved = false;
}
Package::Package(long int id,unsigned int iday,unsigned int imonth,unsigned int iyear,unsigned int oday,unsigned int omonth,unsigned int oyear,string Name){
	name = Name;
	ID = id;
	InTime.Year = iyear;
	InTime.Month = imonth;
	InTime.Day = iday;
	OutTime.Year = oyear;
	OutTime.Month = omonth;
	OutTime.Day = oday;
	retrieved = false;
}
void Package::Retrieve(string Note)
{
	string note = Note;
	time_t t = time(0);
	struct tm now;
	localtime_s( &now,&t);
	OutTime.Year = now.tm_year+1900;
	OutTime.Month = now.tm_mon+1900;
	OutTime.Day = now.tm_mday;
	retrieved = true;
}

void Package::Retrieve(unsigned int day,unsigned int month,unsigned int year,string Note){
	note = Note;
	OutTime.Year = year;
	OutTime.Month = month;
	OutTime.Day = day;
	retrieved = true;
}
