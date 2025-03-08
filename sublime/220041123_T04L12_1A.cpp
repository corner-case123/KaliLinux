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
    freopen("a.in", "r", stdin) ;
    freopen("a.out", "w", stdout) ;
}

const ll mod = 998244353 ;

ll n , m ;
vector<vll> vis , a , score ;
void f (ll i, ll j) {
    if (vis[i][j] == 1) return ;
    //cout << i << j << ln ;
    vis[i][j] = 1 ; score[i][j] += 1 ;
    if (i + 1 < n and a[i][j] <= a[i + 1][j]) f(i + 1, j) ;
    if (i - 1 >= 0 and a[i][j] <= a[i - 1][j]) f(i - 1, j) ;
    if (j + 1 < m and a[i][j] <= a[i][j + 1]) f(i, j + 1) ;
    if (j - 1 >= 0 and a[i][j] <= a[i][j - 1]) f(i, j - 1) ;
    return ;
}
void solve() {
    cin >> n >> m ;
    vis.resize(n, vll(m, 0)) ; score.assign(n, vll(m, 0)) ;
    a.resize(n, vll(m)) ;
    for (auto &r : a) {
        for (auto &e : r) cin >> e ;
    }
    for (ll j = 0; j < m; j++) f(0, j) ;
    for (ll i = 0; i < n; i++) f(i, 0) ;

    vis.assign(n, vll(m, 0)) ;
    //cout << ln ;
    for (ll j = 0; j < m; j++) f(n - 1, j) ;
    for (ll i = 0; i < n; i++) f(i, m - 1) ;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (score[i][j] == 2) cout << 'O' ;
            else cout << 'X'  ;
        }
        cout << ln ;
    }
    return ;
}

int main() {
    setIO() ;
    ll t = 1 ;
    //cin >> t ;
    while (t--) solve() ;
    return 0 ;
}