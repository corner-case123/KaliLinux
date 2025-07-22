#include <bits/stdc++.h>
#define ln '\n'
#define ull unsigned long long
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int> 
#define ld long double
#define tull tuple<ll,ll,ll>
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)



 int main(){

    int n , m , k; cin >> n >> m >> k;  
    vector<vector<pll>> g(n + 1);
    for (int i = 0; i < m; i++) {
        ll u , v , w ; cin >> u >> v >> w ;
        g[u].push_back({v,w}) ;
        g[v].push_back({u,w}) ; // add this for directed
    }


    vector<vll> dis(n + 1, vll(k, 1e17));

    priority_queue<pll, vector<pll>,greater<pll>> pq;
    pq.push({ 0, 1 }); // {dist,node}
    dis[1][0] = 0; // {node,k-th path}

    while (!pq.empty()) {
        // Storing the node value

        auto [d,u] = pq.top() ;
        pq.pop();

        if (dis[u][k - 1] < d) continue;
        vector<pll> v = g[u];

        // Traversing the adjacency list
        for (int i = 0; i < v.size(); i++) {
            auto [dest,cost] = v[i] ;

            // Checking for the cost
            if (d + cost < dis[dest][k - 1]) {
                dis[dest][k - 1] = d + cost;

                // Sorting the distances
                sort(dis[dest].begin(), dis[dest].end());

                // Pushing elements to priority queue
                pq.push({ (d + cost), dest });
            }
        }
    }

    // Printing K shortest paths
    for (int i = 0; i < k; i++) {
        cout << dis[n][i] << " ";
    }
    return 0 ;
}

