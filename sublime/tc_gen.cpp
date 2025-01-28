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


int main (int argc, char **argv) {
  // argv is an array of strings
  // atoi is a C function for converting a string into an int

  srand(stoll(argv[1])); // srand sets the random seed
  ll n = stoll(argv[2]);
  ll x = stoll(argv[3]);

  cout << n << endl;
  for (ll i = 0; i < n-1; i++) {
    cout << 1+rand() % x <<  " "<< 1 + rand() % x << ln ;
  }
  cout << endl;
}