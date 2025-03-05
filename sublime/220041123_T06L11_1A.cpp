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

const ll mod = 998244353 ;

void f(ll col,ll node,vll &vis,vll &color,vector<vll> &g){
    if (vis[node]==1) {
        if (col != color[node]){
            cout << "NO" << ln;
            exit(0) ;
        }
        return ;
    }
    vis[node] = 1 ; color[node] = col ; 
    for(auto &e:g[node]){
        if (col==1) f(2,e,vis,color,g) ;
        else f(1,e,vis,color,g) ; 
    }
}
void solve() {
    ll n ; cin >> n  ;
    vector<vll> g(n+10) ; 
    for(ll i=0;i<n;i++){
        ll m ;  cin >> m ;
        while(m--){
            ll u ; cin >> u ; 
            g[i].push_back(u) ; 
        }
    }
    vll vis(n,0) , color(n,0) ; 
    f(1,0,vis,color,g) ;
    cout << "YES" << ln ;
}

int main(){
    setIO() ;
    ll t = 1 ;  
  // cin >> t ;
    while(t--) solve() ;
    return 0 ;
}