#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	int runs = 10 ;
	freopen("output.txt", "r", stdin);
	for(int i=0;i<runs;i++){
		ll op ; cin >> op ; 
		if (op>(ll)1e8){
			cout << "failed" << endl ;
			return 0;
		}
		cout << "passed" << endl ;
	}
	return 0 ; 
}
