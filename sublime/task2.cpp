#include <bits/stdc++.h>
#define ll long long 
#define ln endl
using namespace std ; 


// Left rotate around node x
Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Right rotate around node y
Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Example usage in check_balance function
Node* check_balance(Node* node) {
    int balance = balance_factor(node);

    // Left Left Case
    if (balance > 1 && balance_factor(node->left) >= 0)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && balance_factor(node->right) <= 0)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && balance_factor(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && balance_factor(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

int main(){
	
	return 0 ;
}