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



ll  n , k , ans ;
string s ;

void f(ll ix,ll level,ll score){
	if (ix==n) {
		if (score>=k) ans =min(ans,level+1) ;
		return ;
	}
	if (s[ix]=='1') score +=level ;
	else score-= level ;
	f(ix+1,level,score) ;
	f(ix+1,level+1,score) ; 
}

int main(){
	cin >> n >> k >> s ;
	ans = 1e15 ;
	f(0,0,0) ;
	if (ans==1e15) cout << -1 << endl ;
	else cout << ans << endl ;
    return 0; 
}

