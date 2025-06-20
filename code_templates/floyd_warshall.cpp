#include <bits/stdc++.h>
#define ln '\n'
#define ull unsigned  long long
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int> 
#define ld long double
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


// proof by induction : 
// assume we have calculated  shortest path for all pairs considering  
// intermediate node from {1,2,3...,k-1}
// for the node  k :
// either shortest path goes through k
// or it does not go through k 
// dp^(k)[i][j] = min(dp^(k-1)[i][j],dp^(k-1)[i][k]+dp^(k-1)[k][j]) ;



int main() {
    fastio ;
    ll n , m , q ; cin >> n >> m >> q;  
    vector<vector<ll>> dp(n,vll(n,1e18)) ; 
    for(ll i=0;i<m;i++){
        ll u ,v ,w ; cin >> u >> v >> w ;
        dp[--u][--v] = w ;
        dp[v][u] = w  ;
        //cout << u << " " << v << " "<< dp[u][v] << endl ;
    }
    for(ll i=0;i<n;i++){
        dp[i][i] = 0 ; 
    }
    for (int k = 0; k < n; k++) {         
        for (int i = 0; i < n; i++) {     
            for (int j = 0; j < n; j++) { 
                if (dp[i][k] < 1e18 and  dp[k][j] < 1e18) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--){
        ll u,v ; cin >> u >> v ; 
        cout << (dp[--u][--v]==1e18?-1:dp[u][v]) << endl ;
    }
    return 0;
}
