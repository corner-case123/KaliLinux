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


ll n , m  ; 
vector<pair<ll,ll>> g ;
vll parent , sz; 
ll find_parent(ll node){
    if (parent[node]==node) return node ;
    return parent[node] = find_parent(parent[node]) ;
}
int main(){
    ll  n , m ; cin >> n >> m ;  
    g.clear() ; g.resize(m) ; 
    sz.clear() ; sz.resize(n,1) ; 
    parent.clear() ;  parent.resize(n) ;
    for(ll i=0;i<n;i++){
        parent[i] = i  ;
    }
    priority_queue<tull,vector<tull>,greater<tull>> pq ;
    for(ll i=0;i<m;i++){
        ll u , v , w ; cin >> u >> v >> w ;
        pq.push({w,--u,--v}) ;
    }
    ll ans = 0 ;
    while(!pq.empty()){
        auto [w,u,v] = pq.top() ;
        pq.pop() ; 
        if (find_parent(u)!=find_parent(v) ){
            if (sz[find_parent(u)]>=sz[find_parent(v)]){
                sz[find_parent(u)] += sz[find_parent(v)] ;
                parent[find_parent(v)] = find_parent(u) ; 
            }
            else {
                sz[find_parent(v)] += sz[find_parent(u)] ; 
                parent[find_parent(u)] = find_parent(v)  ;
            }
            ans += w ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}