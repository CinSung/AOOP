#pragma once
class Staff
{
	string name;
	string position;
	unsigned salary;

public:
	Staff (string _name,string _position,unsigned _salary)
	{
		name=_name;
		position=_position;
		salary=_salary;
	}
};