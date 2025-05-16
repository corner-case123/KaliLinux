#include <bits/stdc++.h>
#define ln endl
#define ull unsigned  long long
#define ll  long long
#define vll vector<ll>
#define ff first
#define ss second
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
using namespace std;


void setIO(const string io = "a") {
    freopen("a.in", "r", stdin) ;
    freopen("a.out", "w", stdout) ;
}

ll n ; 
void solve(){
    cin >> n ;
    cout << n << ln ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setIO() ;
    ll t = 1 ; //cin >> t ;
    while(t--) solve() ;
    return  0 ;
}
