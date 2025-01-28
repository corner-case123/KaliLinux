#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define PLL pair<long long, long long>
#define LL long long
 
#define faster {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ordered_multiset tree<LL, null_type,less_equal<LL>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(),v.end()
 
LL mod = 998244353;
const int N = 2e5 + 10;
LL inf = 1e18 + 7;
 
void solve(int tc) { 
    int n; cin>>n;
    vector<int> g[n + 1];
    vector<int> deg(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    vector<pair<int, int>> order;
    for(int i = 1; i <= n; i++){
        order.push_back({deg[i], i});
    }
    sort(all(order), greater<pair<int, int>>());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = deg[i];
        map<int, int> mp;
        for(auto v: g[i]) mp[v] = 1;
        for(int j = 0; j < min(n, (int)g[i].size() + 2); j++){
            auto [sz, v] = order[j];
            if(v == i) continue;
            if(!mp[v]){
                ans = max(ans, cnt + sz - 1);
            }else{
                ans = max(ans, cnt + sz - 2);
            }
        }
    }
    cout<<ans<<'\n';
}
 
signed main() {
    faster
    int t = 1;
   // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
    return 0;
}