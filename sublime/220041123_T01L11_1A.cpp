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


void solve() {
    ll n ,  m ; cin >> n >>  m ; 
    vector<vll> g(n+1) ; 
    vector<vll> mat(n+1,vll(n+1)) ;
    for(ll i=0;i<m;i++){
        ll u , v ; cin >> u >> v ;
        mat[u][v] = 1 ; mat[v][u] = 1 ; 
        g[u].push_back(v) ; g[v].push_back(u) ; 
    }
    cout << "adjacency list :" << ln ;
    for(ll i=1;i<=n;i++){
        if (g[i].empty()){
            continue ; 
        }
        cout << i << ": "  ; 
        for(auto &e:g[i]) cout << e << " " ; cout << ln ;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout << mat[i][j] << " " ; 
        }
        cout << ln ;
    }
}

int main(){
    setIO() ;
    ll t = 1 ;  
 //  cin >> t ;
    while(t--) solve() ;
    return 0 ;
}