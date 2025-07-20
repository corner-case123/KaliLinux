#include <bits/stdc++.h>
#define ln '\n'
#define ull unsigned long long
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int> 
#define ld long double
#define tull tuple<ll,ll,ll>
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


int main(){
    int n ; cin >> n ; 
    vll a(n) ; for(auto &e:a) cin >> e ;
    ll mx_val = *max_element(a.begin(),a.end()) ;
    for(ll exp=1;mx_val/exp>0;exp*=10){
    	vector<vll> bucket(10) ;
    	for(ll i=0;i<n;i++){
    		ll digit = (a[i]/exp)%10 ;    	
    		bucket[digit].push_back(a[i]) ;
    	}
    	int ix = 0 ;
    	for(ll i=0;i<10;i++){
    		for(auto &e:bucket[i]){
    			a[ix++] = e ;
    		}
    	}
    }
    for(auto &e:a) cout << e << "  " ;
    return 0 ;
}