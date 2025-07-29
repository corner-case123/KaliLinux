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




int main(){
    ll n , k ; cin >>n>>k ;
    vll diff(n,0) ;
    string s ; cin >> s ;
    for(ll i=n-1;i>=0;i--){
        if (s[i]=='1') diff[i]++ ;
        else diff[i]-- ;
    }
    for(ll i=n-2;i>=0;i--){
        diff[i]+=diff[i+1] ;
    }
    ll score = 0 , level = 0;
    multiset<ll> st ;
    for(ll i=0;i<n-1;i++) st.insert(diff[i+1]) ;
    while(!st.empty() and score<k){
        ll val = *(--st.end()) ;
       //cout << val << endl ;//
        st.erase(--st.end()) ;
        if (val) score+=val , level++ ;
    }
    // for(ll i=0;i<n and score<k;i++){    
    //     // if (s[i]=='1') s;
    //     // else score -= diff ;
    //     if (i<n-1 and diff[i+1]>0) level++ ,score+=diff[i+1]; 
    // }
    //cout << score << endl ;
    if (score<k){
        cout << -1 << endl ;
        return 0;
    }
    cout << level+1 << endl ;
    return 0; 
}
