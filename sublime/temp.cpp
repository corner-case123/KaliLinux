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

void solve(){
    ll n ; cin >> n ; 
    vll a(n) ; for(auto &e:a) cin >> e ; 
    set<ll> odd , even ; 
    if (n==4){
        if (a[0]>a[2]){
            swap(a[0],a[2]) ;
            swap(a[1],a[3]) ;
        }
        for(auto &e:a) cout << e << " " ;
        cout << endl ;
        return ;
    }
    for(ll i=0;i<n;i++){
        if (i%2==0) odd.insert(a[i]) ;
        if (i%2==1) even.insert(a[i]) ;
    }
    for(ll i=0;i<n;i++){
        if (i%2==0) {
            cout << *odd.begin() << " " ;
            odd.erase(odd.begin()) ;
        }
        if (i%2==1){
            cout << *even.begin() << " " ;
            even.erase(even.begin()) ;
        }
    }
    cout << endl ;
}

int main(){
    fastio ;
    ll t =  1 ; cin >> t ;
    for(ll i=1;i<=t;i++){
        solve() ;
    }
    return 0  ;
}