#include <bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    uniform_int_distribution<int> n_dist(1, 8); // n in [1,7]
    uniform_int_distribution<int> k_dist(1,64); // k in [1,7]
    uniform_int_distribution<int> bin_dist(0, 1); // For binary digits

    int n = n_dist(rng);
    int k = k_dist(rng);
    cout << n << " " << k << endl ;
    for(int j=0;j<n;j++){
        int  x =  bin_dist(rng);
        cout << (x==1?'1':'0') ;
    }
    cout << endl;
    return 0;
}