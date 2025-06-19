#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

vector<ll> dijkstra(int n, int source, vector<vector<pair<int, ll>>> &adj) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d_u, u] = pq.top(); pq.pop();
        if (d_u > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
