#include "Course.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
Course::Course(string a, string n, float c, float g)
{
	Account = a;
	Name = n;
	Credit = c;
	Grade = g;
}
string Course::getAccount()
{
	return Account;
}
float Course::getCredit()
{
	return Credit;
}
float Course::getGrade()
{
	return Grade;
}
istream& operator>>(istream &in, Course &u)
{
	in >> u.Account >> u.Name >> u.Credit >> u.Grade;
	return in;
}
ostream& operator<<(ostream &out, const Course &u)
{
	out << setw(10) << u.Account << setw(20) << u.Name << setw(8) << u.Credit << setw(8) << u.Grade << endl;
	return out;
}
