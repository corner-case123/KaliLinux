#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define ln '\n'
#define ull unsigned  long long
#define ll long long 
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int> b
#define ld long double
#define ss second
using namespace std;


void setIO(const string io="a"){
    freopen((io+".in").c_str(),"r",stdin) ;
    freopen((io+".out").c_str(),"w",stdout) ;
}


ll cal(vpll &a,ll x,ll y){
	ll sm = 0 ;
	for(auto &e:a){
		sm += abs(e.ff-x) + abs(e.ss-y) ; 
	}
	return sm ; 
}
vll a  ;
void solve(){
	ll n ; cin >> n ;  
	vpll a(n) ; 
	for(auto &e:a) cin  >> e.ff >> e.ss ;  
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO() ;
	ll t = 1 ; cin >> t ;
	for(ll i=1;i<=t;i++){
		solve() ; 
	}
    return 0;
}
