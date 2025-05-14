#include <bits/stdc++.h>
using namespace std;


class Employee {

	int salary , bonus ;
public :
	Employee(int _salary) : salary(_salary), bonus(salary * 10 / 100) {}
	Employee(int _salary, int _bonus) : salary(_salary) , bonus(salary * _bonus / 10) {}
	friend istream& operator >> (istream &, Employee &) ;
	friend ostream& operator << (ostream &, Employee &) ;
} ;
istream& operator >> (istream &in, Employee &e) {
	in >> e.salary ;
	in >> e.bonus ;
	return in ;
}
ostream& operator << (ostream& op, Employee &e) {
	op << e.salary  << '\n' ;
	op << e.bonus << '\n' ;
	return op ;
}


int main() {
	return 0 ;
}