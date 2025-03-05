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


void setIO(const string io="a"){
    freopen((io+".in").c_str(),"r",stdin) ;
    freopen((io+".out").c_str(),"w",stdout) ;
}

const ll mod = 998244353 ;

map<string,ll> ix ;
vector<vll> g ;
vll in ; 
void solve() {
    ll n , m , q ; 
    cin >>  n >> m >> q ;
    //cout << n << m << q ; 
    vector<string> a(n) ;  
    for(ll i=0;i<n;i++){
        cin >> a[i] ;
        ix[a[i]] = i ; 
    }
    g.resize(n) ; in.assign(n,0) ;
    for(ll i=0;i<m;i++){
        string u , v ; cin >> u >> v ;
        g[ix[u]].push_back(ix[v]) ; 
        in[ix[v]]++ ; 
    }
    queue<ll> qu ;
    vll vis(n,0) ;
    for(ll i=0;i<n;i++) {
        if (in[i]==0 and vis[i]==0) qu.push(i); 
    }
    vll top ; 
    while(!qu.empty()){
        ll  node = qu.front() ;
        qu.pop() ; vis[node] = 1 ;
        top.push_back(node) ;
        for(auto &e:g[node]){
            if (--in[e]==0) qu.push(e) ;
        }
    }
    for(ll i=0;i<n;i++){
        if (in[i]!=0){
            cout << "IMPOSSIBLE" << ln ;
            exit(0) ;
        }
    }
    for(auto &e:top){
        cout << a[e] << " " ; 
    }
    cout << ln ;
    while(q--){
        string a ,b ; cin >> a >> b; 
        ll u = ix[a] , v = ix[b] ; 
        if (find(top.begin(),top.end(),u)>find(top.begin(),top.end(),v) ){
            cout << "YES" << ln ;
        }
        else cout << "NO" << ln ;
    }
}

int main(){
    setIO() ;
    ll t = 1 ;  
     //cin >> t ;
    while(t--) solve() ;
    return 0 ;
}