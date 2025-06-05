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

// merge sort tree for range frequency queries
// it is based on std segment tree 
struct MergeSortTree {
    ll n;
    vector<vector<ll>> tree;

    MergeSortTree(const vector<ll>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    void build(const vector<ll>& a, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = {a[l]};
            return;
        }
        ll mid = (l + r) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);

        // merge function merges 2 sorterd vectors into one append them into tree[node]
        // super_cool
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              back_inserter(tree[node]));
    }

    // query: count elements <= x in range [ql, qr]
    ll query(ll node, ll l, ll r, ll ql, ll qr, ll x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr)
            return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
        ll mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr, x) +
               query(2 * node + 1, mid + 1, r, ql, qr, x);
    }
};

int main() {
    return 0;
}
