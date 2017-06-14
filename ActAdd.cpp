#include "ActAdd.h"
#include <iomanip>
ActAdd::ActAdd(string a, string n, string t, float g, string y)
{
	Account = a;
	Name = n;
	Type = t;
	Grade = g;
	Get = y;
}
string ActAdd::getAccount()
{
	return Account;
}
string ActAdd::getType()
{
	return Type;
}
float ActAdd::getGrade()
{
	return Grade;
}
void ActAdd::modifyGet(int n)
{
	if (n == 1)
		Get = "���ͨ��";
	if (n == 2)
	{
		Get = "���δͨ��";
		Grade = 0;
	}
}
string ActAdd::getGet()
{
	return Get;
}
istream& operator>>(istream &in, ActAdd &u)
{
	in >> u.Account >> u.Name >> u.Type >> u.Grade >> u.Get;
	return in;
}
ostream& operator<<(ostream &out, const ActAdd &u)
{
	out << setw(10) << u.Account << setw(20) << u.Name << setw(12) 
		<< u.Type << setw(8) << u.Grade << setw(14) << u.Get << endl;
	return out;
}
