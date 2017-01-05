#pragma once
class Accounts
{
	unsigned cash;
	unsigned icash;
	unsigned creditcard;

public:
	void setcash(int a){cash = (int) a;}
	void seticash(int b){icash = (int) b;}
	void setcreditcard(int c){creditcard = (int) c;}

	Accounts()
	{
	}
	Accounts (const Accounts &b)
	{
		cash=b.cash;
		icash=b.icash;
		creditcard=b.creditcard;
	}

};