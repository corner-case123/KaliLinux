#include <bits/stdc++.h>
#define ll long long
#define ln endl
using namespace std;

struct node {
    ll val;
    node* rp = NULL;
    node* lp = NULL;
    node* par = NULL;
    ll h = 0;
    node(ll x) : val(x) {}
};

class AVLTree {
public:
    node* head = NULL;

    void insert(ll x) {
        node* n = new node(x);
        if (head == NULL) {
            head = n;
            printStatus("Balanced", head);
            return;
        }
        node* tem = head;
        while (true) {
            if (n->val > tem->val) {
                if (tem->rp == NULL) {
                    tem->rp = n;
                    n->par = tem;
                    updateHeight(n);
                    balance(n);
                    return;
                } else {
                    tem = tem->rp;
                }
            } else {
                if (tem->lp == NULL) {
                    tem->lp = n;
                    n->par = tem;
                    updateHeight(n);
                    balance(n);
                    return;
                } else {
                    tem = tem->lp;
                }
            }
        }
    }

    void updateHeight(node* n) {
        while (n != NULL) {
            ll lh = (n->lp) ? n->lp->h + 1 : 0;
            ll rh = (n->rp) ? n->rp->h + 1 : 0;
            n->h = max(lh, rh);
            n = n->par;
        }
    }

    ll balance_factor(node* n) {
        ll lh = (n->lp) ? n->lp->h + 1 : 0;
        ll rh = (n->rp) ? n->rp->h + 1 : 0;
        return lh - rh;
    }

    node* left_rotate(node* x) {
        node* y = x->rp;
        x->rp = y->lp;
        if (y->lp != NULL) y->lp->par = x;
        y->par = x->par;

        if (x->par == NULL) head = y;
        else if (x == x->par->lp) x->par->lp = y;
        else x->par->rp = y;

        y->lp = x;
        x->par = y;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    node* right_rotate(node* y) {
        node* x = y->lp;
        y->lp = x->rp;
        if (x->rp != NULL) x->rp->par = y;
        x->par = y->par;

        if (y->par == NULL) head = x;
        else if (y == y->par->lp) y->par->lp = x;
        else y->par->rp = x;

        x->rp = y;
        y->par = x;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    void balance(node* n) {
        while (n != NULL) {
            updateHeight(n);
            ll bf = balance_factor(n);

            if (bf > 1) {  // Left heavy
                if (balance_factor(n->lp) < 0) {  // Left-Right case
                    cout << "Imbalance at node: " << n->val << ln;
                    cout << "LR Case" << ln;
                    n->lp = left_rotate(n->lp);
                    cout << "Left_rotate(" << n->lp->val << ")" << ln;
                }
                cout << "Imbalance at node: " << n->val << ln;
                cout << "LL case" << ln;
                n = right_rotate(n);
                cout << "Right_rotate(" << n->val << ")" << ln;
                printStatus("Status", head);
            }
            else if (bf < -1) {  // Right heavy
                if (balance_factor(n->rp) > 0) {  // Right-Left case
                    cout << "Imbalance at node: " << n->val << ln;
                    cout << "RL Case" << ln;
                    n->rp = right_rotate(n->rp);
                    cout << "Right_rotate(" << n->rp->val << ")" << ln;
                }
                cout << "Imbalance at node: " << n->val << ln;
                cout << "RR case" << ln;
                n = left_rotate(n);
                cout << "Left_rotate(" << n->val << ")" << ln;
                printStatus("Status", head);
            }
            n = n->par;
        }

        printStatus("Balanced", head);
    }

    void inorder(node* n) {
        stack<node*> stack;
        node* current = n;
        while (current != NULL || !stack.empty()) {
            while (current != NULL) {
                stack.push(current);
                current = current->lp;
            }
            current = stack.top();
            stack.pop();
            cout << current->val << "(" << current->h << ") ";
            current = current->rp;
        }
    }

    void printStatus(const string& status, node* root) {
        inorder(root);
        cout << ln;
        cout << status << ln;
        if (root) {
            cout << "Root=" << root->val << ln;
        }
    }
};

int main() {
    AVLTree bst;
    ll x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        bst.insert(x);
    }
    return 0;
}
