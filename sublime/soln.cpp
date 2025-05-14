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
vpll ans ;
set<pll> st ;
void f(pll p){
    if (st.find(p)!=st.end()) return ;
    cout << "? " << p.ff << " " << p.ss  << ln ;
    ll x  ;  cin >> x ;
    if (x==p.ff) {
        ans.push_back({p.ff,p.ss}) ;
        st.insert({p.ff,p.ss}) ;
        return  ;
    }
    f({x,p.ss}) ;
}




void solve(){
    cin >> n ;
    ans.clear() ; st.clear() ;
    for(ll i=2;i<=n;i++){
        f({1,i}) ;
    }
    cout << "! " ;
    for(auto &p:ans) cout << p.ff << " " << p.ss << " " ;
    cout << endl ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setIO() ;
    ll t = 1 ; cin >> t ;
    while(t--) solve() ;
    return  0 ;
}
