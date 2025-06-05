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
#define pii pair<int,int> b
#define ld long double
#define ss second
using namespace std;


void setIO(const string io = "a") {
    freopen("in.txt", "r", stdin) ;
    freopen("out.txt", "w", stdout) ;
}
ll n ; 
// f means we want to move (1 to val) from src to dest using help
// strat as follow : 
//     we move (1 to n-1) from src to help using dest
//     then we move n from src to dest
//     after that we have to move (1 to n-1) from help to dest using src
// this process keeps happening recursively 

void f(string src,string dest,string help,ll val){
    if (val==1){
        cout << val << " from " + src + " to " + dest << endl ;
        return ; 
    }
    f(src,help,dest,val-1) ;
    cout << val << " from " + src + " to " + dest << endl ; 
    f(help,dest,src,val-1) ; 
}

int main(){
    f("src","dest","help",3) ;
    return 0  ;
}