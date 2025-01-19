#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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


void setIO(const string io="a"){
    freopen((io+".in").c_str(),"r",stdin) ;
    freopen((io+".out").c_str(),"w",stdout) ;
}

class DSU {
private:
    vector<ll> parent; // Stores the parent of each node
    vector<ll> size;   // Stores the size of the set for union by size

public:
    // Constructor: Initializes DSU with n elements (0 to n-1)
    DSU(ll n) {
        parent.resize(n);
        size.resize(n, 1); // Initially, each set has size 1
        for (ll i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent
        }
    }

    // Find function with path compression
    ll find(ll x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function with union by size
    bool unite(ll a, ll b) {
        ll rootA = find(a);
        ll rootB = find(b);

        if (rootA == rootB) {
            return false; // a and b are already in the same set
        }

        // Union by size: attach the smaller tree under the larger tree
        if (size[rootA] < size[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        size[rootA] += size[rootB];
        return true;
    }

    // Function to check if two elements are in the same set
    bool isConnected(ll a, ll b) {
        return find(a) == find(b);
    }

    // Function to get the size of the set containing element x
    ll getSetSize(ll x) {
        return size[find(x)];
    }
};

vector<vll> f ;
vll fvis ; 
ll sz = 0 , del = 0 ; 
void func(ll n,DSU &d1,DSU &d2,ll par){
	if (fvis[n]>=par) return ; 
	cout << n << ln ;
	fvis[n] = par ; sz++ ; 
	for(auto &ch:f[n]){
		if (fvis[ch]>=par) continue ; 
		else if (d2.isConnected(ch,n)){
			//cout << n <<  " " << ch << ln ;
			func(ch,d1,d2,par) ;
		}
		else if (!d2.isConnected(ch,n)){
			cout << n <<  " " << ch << ln ;
			 del++ ;  
		}
	}  
	return ; 
}
void solve(){
	
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	setIO() ;
	ll t = 1 ; 
	cin >> t ;
	for(ll i=1;i<=t;i++){
		//cout << "Case " << i << ": " ;
		solve() ;
	}
    return 0;
}

