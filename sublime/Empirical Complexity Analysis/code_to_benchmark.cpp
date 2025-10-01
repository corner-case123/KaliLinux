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




void solve(){
    ll n ; cin >> n ; 
    vll a(n) ; for(auto &e:a) cin >> e ;
    unordered_set<ll> st ; 
    unordered_map<ll,ll> cnt , red ;
    ll sm = 0 ;
    ll mx_so_far = 0 , ix = -1;

    ll op = 0 ;
    for(auto &e:a){
        if (e==0) cnt[0]++ , st.insert(0) ;
        else if (cnt[e-1]-red[e-1]>0) { // O(1)
            op++ ;
            cnt[e]+= (cnt[e-1]-red[e-1]) ;
            cnt[e-1] -= (cnt[e-1]-red[e-1]);
            if (cnt[e-1]==0) st.erase(e-1) ;
            st.insert(e) ;
        }
        for(auto &ele:st){ // 
            op++ ;
            sm += cnt[ele]*(ele+1) ;
        }
        for(auto &ele:st){ // 
            op++ ;
            if(ele<e){
                red[ele] = cnt[ele] ;
            }
        }
    }
    cout << op << endl ;
    //cout << sm << endl; 
}
int main() {
    fastio;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}
