#include <bits/stdc++.h>
using namespace std;

class Account {
protected :
	string holder_name , account_number , status ;
	int balance ;

public :
	Account() {}

} ;
class Savings : public Account {
	int withdraw_cnt , deposit_cnt , withdraw_limit;
public :
	Savings() : withdraw_cnt(5), deposit_cnt(5), withdraw_limit(10000) {}

} ;

class Current : public Account {
	const int cost = 1000 ;
public :
} ;

class Transaction {

} ;

class Bank {
private :
	string name ;
	vector<Account> acc ;
	vector<Transaction> trans ;
public :
	void reset_limit() {

	}
} ;


int main() {

}