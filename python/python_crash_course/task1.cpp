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

bool f(string &s, ll m) {
    ll  l = 0 , r = s.size() - 1 ;
    while (l <= r) {
        if (s[l] != s[r]) {
            ll l1 = l + m , r1 = r - m ;
            while (l1 <= r1) {
                if (s[l1] != s[r1]) {
                    return 0  ;
                }
                l1++ ; r1--;
            }
            multiset<char> st1 , st2  ;
            for (ll j = l; j < l + m and j < s.size(); j++) {
                st1.insert(s[j]) ;
            }
            for (ll j = r; j >= 0 and j > r - m; j--) {
                st2.insert(s[j]) ;
            }
            if (st1 != st2) return  0 ;
            l += m ; r -= m ;
        }
        l++ ; r-- ;
    }
    return 1 ;
}
void solve() {
    string s ; cin >> s ;
    ll n  = s.size() ;
    ll l = 0 , r  = n ;
    ll ans = n - 1 ;
    while (l <= r) {
        ll m = (l + r) / 2 ;
        if (f(s, m)) {
            ans = min(ans, m) ; r = m - 1 ;
        }
        else {
            l  = m + 1 ;
        }
    }
    cout << ans << ln ;
}

int main() {
    setIO() ;
    ll t = 1 ;
    cin >> t ;
    while (t--) solve() ;
    return 0 ;
}