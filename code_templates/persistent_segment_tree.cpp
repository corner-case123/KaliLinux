#include <bits/stdc++.h>
#define ln '\n'
#define ll long long
#define vll vector<ll>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

// Persistent segment tree for point updates and range sum queries

// core idea of update method : 
// in persistent segment tree whenever there is a  update a new tree(head/root) is created 
// but in this new tree only the nodes that needs change are changed
// all the other nodes are copied from previous version (reference copy)
struct PersistentSegmentTree {
    struct Node {
        ll val;
        Node* left;
        Node* right;
        Node(ll v = 0) : val(v), left(nullptr), right(nullptr) {}
    };

    ll n;
    vector<Node*> versions;

    PersistentSegmentTree(const vector<ll>& a) {
        n = a.size();
        Node* root = build(a, 0, n - 1);
        versions.push_back(root);
    }

    Node* build(const vector<ll>& a, ll l, ll r) {
        if (l == r) return new Node(a[l]);
        ll mid = (l + r) / 2;
        Node* node = new Node();
        node->left = build(a, l, mid);
        node->right = build(a, mid + 1, r);
        node->val = node->left->val + node->right->val;
        return node;
    }

    // this is the most important method
    Node* update(Node* prev, ll l, ll r, ll idx, ll val) {
        if (l == r) return new Node(val);
        ll mid = (l + r) / 2;
        Node* node = new Node();
        if (idx <= mid) {
            node->left = update(prev->left, l, mid, idx, val);
            node->right = prev->right;
        } else {
            node->left = prev->left;
            node->right = update(prev->right, mid + 1, r, idx, val);
        }
        node->val = node->left->val + node->right->val;
        return node;
    }

    ll query(Node* node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return node->val;
        ll mid = (l + r) / 2;
        return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
    }

    // Public interface
    void update(ll version_idx, ll idx, ll val) {
        Node* new_version = update(versions[version_idx], 0, n - 1, idx, val);
        versions.push_back(new_version);
    }

    ll query(ll version_idx, ll ql, ll qr) {
        return query(versions[version_idx], 0, n - 1, ql, qr);
    }
};


int main() {
    fastio;
    vector<ll> a = {1, 2, 3, 4, 5};
    PersistentSegmentTree pst(a);

    cout << pst.query(0, 0, 4) << ln; // 1+2+3+4+5 = 15

    pst.update(0, 2, 10); // update index 2 to 10 in version 0 → version 1
    cout << pst.query(1, 0, 4) << ln; // 1+2+10+4+5 = 22

    pst.update(1, 0, 7); // update index 0 to 7 in version 1 → version 2
    cout << pst.query(2, 0, 2) << ln; // 7+2+10 = 19

    cout << pst.query(0, 0, 2) << ln; // back to version 0 → 1+2+3 = 6

    return 0;
}
