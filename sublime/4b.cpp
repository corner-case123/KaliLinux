#include <bits/stdc++.h>
using namespace std;


class Base {
	int a  ;
public :
	Base(int _a) : a(_a) {}
} ;

class Der : public Base {
	int  b ;
public :
	Der(int _a, int _b = 10) : Base(_a) , b(_b) {}
} ;


int main() {
	Der d(2) ;
	return 0;
}