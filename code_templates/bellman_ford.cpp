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
#define ss second
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


// the shortest path from the source to any vertex can be at most n - 1 edges long.
// On each pass, Bellman-Ford considers all edges and relaxes them.
// So, in one iteration, we might discover paths of length 1.
// In two iterations, paths of length up to 2.
// After i iterations, we will have found all shortest paths that use ≤ i edges.
// After n - 1 Iterations
// All shortest paths (with ≤ n - 1 edges) will have been fully relaxed.
// Hence, further relaxation won't improve any distance if there's no negative cycle.


int main() {
    fastio;

    ll n, m ; cin >> n >> m ;
    vector<vll> edges; 

    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back({--u, --v, w});
    }

    vll dp(n, 1e18);
    dist[0] = 0; // every node is considered as a source 
    // in this task we only need to verify negative cycle
    for (ll i = 1; i < n; i++) {
        for (auto &e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            if (dp[u] < 1e18 && dp[u] + w < dp[v]) {
                dp[v] = dp[u] + w;
            }
        }
    }
    for (auto &e : edges) {
        ll u = e[0], v = e[1], w = e[2];
        if (dp[u] < 1e18 && dp[u] + w < dp[v]) {
            cout << "YES" << endl ;
            return ;
        }
    }
    cout << "NO" << endl ; 
    return 0;
}
