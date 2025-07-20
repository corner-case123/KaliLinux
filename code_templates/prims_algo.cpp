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
	ll n , m ; cin >> n >> m ;  
	vll inMST(n,0) ; inMST[0] = 1 ; 
	vector<vector<pll>> g(n) ; 
	priority_queue<pll,vector<pll>,greater<pll>> pq ;
	for(ll i=0;i<m;i++){
		ll u , v , w ; cin >> u >> v >> w ;
		--u ; --v; 
		g[u].push_back({v,w}) ;
		g[v].push_back({u,w}) ;
	} 
	for(auto [ch,w]:g[0]) pq.push({w,ch}) ;
	ll ans = 0 ; 
	while(!pq.empty()){
		auto [w,v] = pq.top() ;
		pq.pop() ;
		if (inMST[v]==1) continue ;
		inMST[v] = 1 ; 
		ans += w ;
		for(auto [ch,w]:g[v]) pq.push({w,ch}) ;
	}
	cout << ans << endl ;
	return 0 ; 
}