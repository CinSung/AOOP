#pragma once
class Account
{
	unsigned cash;
	unsigned icash;
	unsigned creditcard;

public:
	void setcash(int a){cash = (int) a;}
	void seticash(int b){icash = (int) b;}
	void setcreditcard(int c){creditcard = (int) c;}

	Account()
	{
	}
	Account (const Account &b)
	{
		cash=b.cash;
		icash=b.icash;
		creditcard=b.creditcard;
	}

};