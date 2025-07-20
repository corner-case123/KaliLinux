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
#define tull tuple<ll,ll,ll>
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


int main(){
    int n ; cin >> n ; 
    vll a(n) ; for(auto &e:a) cin >> e ;
    ll mx_val = *max_element(a.begin(),a.end()) ;
    for(ll exp=1;mx_val/exp>0;exp*=10){
        vll pre(10,0) ;
        for(ll i=0;i<n;i++){
            pre[(a[i]/exp)%10]++ ;
        }
        for(ll i=1;i<10;i++){
            pre[i]+=pre[i-1] ;
        }
        vll output(n) ; 
        for(ll i=n-1;i>=0;i--){
            ll digit = (a[i]/exp)%10 ;
            output[--pre[digit]] = a[i] ; // 0 based indexing
        }
        a = output ;
    }
    for(auto &e:a) cout << e << " " ;
    return 0 ; 
}