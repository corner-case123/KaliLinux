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


void setIO(const string io = "a") {
    freopen("in.txt", "r", stdin) ;
    freopen("out.txt", "w", stdout) ;
}

const ll mod = 998244353 ;

void solve() {
    ll n , q  ;  cin >> n >> q ;
    vll a(n) ; for (auto &e : a) cin >> e ;
    vll p(n) ;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) p[i]++ ;
        else p[i]-- ;
        if (i > 0) p[i] += p[i - 1] ;
    }
    while (q--) {
        ll l , r ; cin >> l >> r ;
        l-- ; r-- ;
        ll val = abs(p[r] -  ((l > 0) ? p[l - 1] : 0) ) ;
        if (val % 2 == 0) cout << val / 2 << ln ;
        else cout << -1 << ln ;
    }
}

int main() {
    setIO() ;
    ll t = 1 ;
    //cin >> t ;
    while (t--) solve() ;
    return 0 ;
}