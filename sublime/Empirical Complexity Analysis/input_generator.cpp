#include <bits/stdc++.h>
using namespace std;
#define ll long long 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    freopen("input.txt", "w", stdout);
    //uniform_int_distribution<int> n_dist(1, 1e6); // n in [l,r]
    uniform_int_distribution<int> k_dist(0,(int)1000000); // k in [l,r]
    int x = k_dist(rng) ;

    ll test = 10 ;
    cout <<test << endl ;    
    for(int i=0;i<test;i++){
        cout << (int)1e6 << endl ;
        for(int j=0;j<(int)1e6;j++){
            int x = k_dist(rng) ;
            cout << x << " " ;
        }
        cout << endl;
    }
    return 0;
}