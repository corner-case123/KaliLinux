#include <bits/stdc++.h>
#define ll long long 
#define ln '\n'
#define vll vector<ll> 
#define ss second
#define ff first 
using namespace std;




int main(){
	string  s ;  
	unordered_map<string,ll> ct ; 
	while(cin>>s){
		string s1 = "" ;
		for(auto e:s){
			if ('A' <= toupper(e) and toupper(e)<='Z'){
				s1 += e ;
			}
		}
		if (s1!="")ct[s1]++ ;
	}
	for(auto e:ct){
		if (e.ss>1){
			cout << e.ff << " " << e.ss << ln ;
		}
	}
	return 0 ; 
}