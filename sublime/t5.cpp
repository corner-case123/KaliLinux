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
    ll n ;  cin >> n ;
    vll a(n)  ; for (auto &e : a) cin >> e ;
    vector<vll> sparse(n, vll (log2(n) + 10) ) ;
    for (ll i = 0; i < n; i++) {
        sparse[i][0] = a[i] ;
    }
    for (ll j = 1; j <= log2(n) + 10; j++) {
        for (ll i = 0; i < n; i++) {
            if (i + (1ll << j) > n) {
                break ;
            }
            sparse[i][j] = __gcd(sparse[i][j - 1] , sparse[i + (1ll << (j - 1))][j - 1]) ;
            //cout << i << " " << j << " " << sparse[i][j] << ln ;
        }
    }
    ll q ; cin >> q  ;
    while (q--) {
        ll l ,  r ;  cin >> l >> r ;
        ll pw = log2(r - l + 1) ;
        //cout << l << " " << r << " " << pw << ln ;
        //cout << sparse[l][pw] << " " <<   sparse[r - (1ll << pw) + 1][pw]  << ln ;
        cout << __gcd(sparse[l][pw], sparse[r - (1ll << pw) + 1][pw]) << ln ;
    }
}

int main() {
    setIO() ;
    ll t = 1 ;
    //cin >> t ;
    while (t--) solve() ;
    return 0 ;
}