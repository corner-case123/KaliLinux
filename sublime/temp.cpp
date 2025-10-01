#include <bits/stdc++.h>
#define ln '\n'
#define ll long long 
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 

int palindrome(int i,int j,string s){
    if (i>j) return 1 ;
    if (s[i]==s[j]) return palindrome(i+1,j-1,s) ;
    return 0 ; 
}
void solve(){
    string word = "abccba" ;
    printf("%d",palindrome(0,5,word)) ;

    return ;
}

int main() {
    fastio;
    ll t = 1;  //cin >> t;
    while(t--) solve();
    return 0;
}