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
    ll n ,  m ; cin >> n >> m ; 
    vll degree(n+1,0) ;
    for(ll i=0;i<m;i++){
        ll u , v ; cin >> u >> v;  
        degree[u]++ ; degree[v]++ ;
    }
    for(ll i=1;i<=n;i++){
        if (degree[i]!=degree[1]){
            cout << "NO" << ln ;
            return ;
        }
    }
    cout << "YES" << ln ;
}

int main(){
    setIO() ;
    ll t = 1 ;  
 //  cin >> t ;
    while(t--) solve() ;
    return 0 ;
}