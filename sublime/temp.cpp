#include <bits/stdc++.h>
#define ln '\n'
#define ull unsigned long long
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
    ll n , m ; cin >> n >> m ;  
    ll mn = n , mx = (n*(n+1) )/2 ;  
    vll ans ; 
    if (m>mx or m<mn){
        cout << -1 << endl ;
        return ;
    }
    ll i = 1 ; 
    for(;i<=n;i++){
        ll val = (n-i+1) +  (  (i-1)*(n+ n-(i-2)) )/2 ;
        if (n-(i-2)<=1) continue ; 
        if (m<=val) break ; 
    }

    // use len i 
    //cout << i << endl ;
    set<ll> st ; for(ll i=1;i<=n;i++) st.insert(i) ;
    if (i==1){
        for(ll val=1;val<=n;val++){
            ans.push_back(val) ; 
        }
    }
    else if (i==2){
        ans.push_back(m-(n-1) ) ;
        for(ll j=1;j<=n;j++){
            if ( j!=(m-(n-1))){
                //cout << j << endl ;
                ans.push_back(j) ;
            }
        }
    }
    else {
        for(ll top=1;top<=n;top++){
            if (top-(i-3)<=0) {
                continue ;
            }
            ll val = (n-i+1) +  (  (i-1-1)*(n+ n-(i-2-1)) )/2 ;

            if ( m-val<=1 or m-val>=n-(i-2-1) ) {
                continue ;
            }
            //cout << top << endl ;
            ll x = i-2 , p_val = top ; 
            while(x--){
                ans.push_back(p_val) ;
                st.erase(p_val) ;
                p_val-- ;  
            }
            ans.push_back(1) ; st.erase(1) ;
            for(auto &e:st) ans.push_back(e) ;
            if (!ans.empty()){
                break ;
            }
        }    
    }
    cout << ans[0] << endl ;
    for(ll i=0;i<n-1;i++){
        cout << ans[i] << " " << ans[i+1] << endl ;
    }
    return ;
}
int main() {
    fastio;
    ll t =1; cin >> t  ;
    while(t--) solve() ;
    return 0;
}
