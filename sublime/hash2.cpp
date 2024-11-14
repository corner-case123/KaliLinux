#include <bits/stdc++.h>
#define ll long long 
#define ln '\n'
#define vll vector<ll> 
#define ss second
#define ff first 
using namespace std;




int main(){
	unordered_map<ll,ll> mp; 
	ll x ;
	while(true){
		cin >> x ; 
		if (x==-1) break ; 
		mp[x]++  ;
	}
	ll t ; cin >> t ;
	ll ok = 0 ;
	for(auto p:mp){
		ll e = p.ff ;
		if (e==t-e){
			if (mp[e]>1){
				cout << "(" << e << "," << e << "), " ; 
				ok =  1 ;
			}
		}
		else {
			if (e>t-e and mp.find(t-e)!=mp.end()){
				cout << "(" << e << "," << t-e << "), " ; 
				ok =  1 ;
			}
		}
	}
	if (ok==0) cout << "No pairs found" << ln ;
	return 0 ;
}