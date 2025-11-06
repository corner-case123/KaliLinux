#include <bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define ff first
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)



ll s  ;
void solve() {
    ll n; cin >>n ;
    vll a(n) ; for(auto &e:a) cin >> e ;
    sort(a.begin(),a.end()) ;
    vll p = a ; for(ll i=1;i<n;i++) p[i]+= p[i-1] ; 
    if (s==0){
        if (n%2){
            cout << accumulate(a.begin(),a.begin()+(n+1)/2,0ll) << endl ;
        }
        else {
            cout << accumulate(a.begin()+1,a.begin()+1+n/2,0ll) << endl ;
        }
    }
    else {
        ll mx = 0; 
        for(ll i=n-1;i>=0;i--){
            ll l = max(i-(n-1-i),0ll) ;
            mx = max(mx,p[i]-(l==0)?0:p[l-1]) ;
        }
        cout << mx << endl ;
    }
}

int main() {
    fastio;
    
    ll t =1 ; cin >> t>> s ;
    for(ll i=1;i<=t;i++){

        solve() ;
    }
    return 0;
}
