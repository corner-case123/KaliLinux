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
vector<vll> vis  ;
vector<string> a  ;
ll ct  = 0 ;
void f (ll i, ll j) {
    if (vis[i][j] == 1 or a[i][j] == '0') return ;
    vis[i][j] = 1 ;
    if (i + 1 < n) f(i + 1, j) ;
    if (i - 1 >= 0) f(i - 1, j) ;
    if (j + 1 < m) f(i, j + 1) ;
    if (j - 1 >= 0) f(i, j - 1) ;
}
void solve() {
    cin >> n >> m ;
    a.resize(n)  ; for (auto &s : a) cin >> s ;
    vis.resize(n, vll(m, 0)) ;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (vis[i][j] == 0 and a[i][j] == '1') {
                ct++ ;
                f(i, j) ;
            }
        }
    }
    cout << ct << ln ;
}

int main() {
    setIO() ;
    ll t = 1 ;
    //cin >> t ;
    while (t--) solve() ;
    return 0 ;
}