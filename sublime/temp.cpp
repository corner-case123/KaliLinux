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
    ll n ; cin >> n  ; 
    vll a(n) ; for(auto &e:a) cin >> e ; 
    set<tuple<ll,ll,ll>> total_emp , emp ; 
    ll cnt = 0 ;
    map<tuple<ll,ll>,ll> so_far; 
    for(ll total=0;;total++){
        for(ll x=0;x<=total;x++){
            ll y = total-x ; 
            total_emp.insert({3*x+3*y+2,3*x+1,3*y+1}) ; 
            emp.insert({3*x+3*y+2,3*x+1,3*y+1}) ; 
            cnt++ ; 
        }
        if (cnt>=n) {
            break; 
        }
    }

    //for(auto [dist,x,y]:total_emp) cout << dist << " " << x << " " << y << endl ; 

    vpll ans  ;
    for(auto &e:a){
        // for(auto [dist,x,y]:emp){
        //     cout << dist << " " << x  << " " << y << endl ;
        // }
        // cout << endl ;
        if (e==1){ 
            auto [dist,x,y] = *emp.begin()  ;
            //cout << dist << " " << x << " " << y << endl ; 
            ll val = ++so_far[{x,y}] ;

            if (val==1){
                total_emp.erase({dist,x,y})  ;
                ans.push_back({x,y}) ; 
                emp.insert({dist+1,x,y+1}) ; 
                so_far[{x,y+1}] = 1 ; 
            }
            else if (val==2){
                ans.push_back({x,y}) ; 
                emp.insert({dist,x+1,y-1}) ; 
                so_far[{x+1,y-1}] = 2 ;  
            }
            else if (val==3){
                ans.push_back({x,y}) ;  
                emp.insert({dist+3,x,y+1}) ; 
                so_far[{x,y+1}] = 3 ;  
            }
            else {
                ans.push_back({x,y}) ;
            }
            emp.erase({dist,x,y}) ; 
        }
        else{
            auto [dist,x,y] = *total_emp.begin()  ;
            //cout << dist << " " << x << " " << y << endl ;

           
            emp.erase(*total_emp.begin())  ; 
            total_emp.erase(*total_emp.begin())  ; 
            ans.push_back({x,y}) ; 
            emp.insert({dist+1,x,y+1}) ; 
            so_far[{x,y+1}] = 1 ; 
        }
    }
    for(auto [x,y]:ans){
        cout << x << " " << y << endl ;
    }

}

int main(){
    fastio ;
    ll t =  1 ; cin >> t ;
    for(ll i=1;i<=t;i++){
        solve() ;
    }
    return 0  ;
}