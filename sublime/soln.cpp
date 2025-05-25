#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


void setIO(const string io = "a") {
    freopen("a.in", "r", stdin) ;
    freopen("a.out", "w", stdout) ;
}


void pre()
{
    fastio ; 

    
}

void customSwap(int& a, int& b)
{
    if (&a==&b) return ; 
    a  = a^b ; 
    b = a^b  ;
    a =  a^b ;    
}

void solve(int tc)
{
    int a, b;
    cin >> a >> b;
    customSwap(a, a) ;
    customSwap(a, b);
    
    cout << a << "  " << b << '\n';
}

signed main()
{
    pre();
    setIO() ; 
    int tc, tt = 1;
    // cin >> tt;
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        // cout << '\n';
    }

    return 0;
}