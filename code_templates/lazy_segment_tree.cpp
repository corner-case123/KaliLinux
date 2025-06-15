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



// lazy segment tree for range sum queries with range updates
struct LazySegmentTree {
    ll n;
    vector<ll> tree, lazy;

    LazySegmentTree(const vector<ll>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    ll build(const vector<ll>& a, ll node, ll l, ll r) {
        if (l == r) return tree[node] = a[l];
        ll mid = (l + r) / 2;
        return tree[node] = build(a, 2 * node, l, mid) + build(a, 2 * node + 1, mid + 1, r);
    }

    // update a tree[node] only when we have to use it 
    void push(ll node, ll l, ll r) {
        if (lazy[node]) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                // mark the children that they need update too later
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    // in both update and query method we are pushing only when we need the node updated 
    ll update(ll node, ll l, ll r, ll ql, ll qr, ll val) {
        push(node, l, r); // complete pending node update
        if (qr < l || ql > r) return tree[node];
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return tree[node];
        }
        ll mid = (l + r) / 2;
        return tree[node] = update(2 * node, l, mid, ql, qr, val) +
                            update(2 * node + 1, mid + 1, r, ql, qr, val);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        push(node, l, r);// complete pending node updates 
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        ll mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    fastio;
    vector<ll> a = {1, 2, 3, 4, 5};
    LazySegmentTree st(a);

    cout << "Initial sum(1,3): " << st.query(1, 3) << ln; // Output: 2+3+4 = 9
    st.update(1, 3, 5);  // Add 5 to range [1,3]
    cout << "After update sum(1,3): " << st.query(1, 3) << ln; // Output: 7+8+9 = 24
    cout << "sum(0,4): " << st.query(0, 4) << ln; // Output: 1 + 7 + 8 + 9 + 5 = 30

    return 0;
}