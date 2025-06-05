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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


// segment tree for sum
struct SegmentTree {
    ll n;
    vector<ll> tree;

    SegmentTree(const vector<ll>& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    ll build(const vector<ll>& a, ll node, ll l, ll r) {
        if (l == r) return tree[node] = a[l];
        ll mid = (l + r) / 2;
        return tree[node] = build(a, 2 * node, l, mid) + build(a, 2 * node + 1, mid + 1, r);
    }

    ll update(ll node, ll l, ll r, ll idx, ll val) {
        if (l == r) return tree[node] = val;
        ll mid = (l + r) / 2;
        if (idx <= mid)
            return tree[node] = update(2 * node, l, mid, idx, val) + tree[2 * node + 1];
        else
            return tree[node] = tree[2 * node] + update(2 * node + 1, mid + 1, r, idx, val);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        ll mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main(){
    return 0 ;
}