#include <bits/stdc++.h>
#define ll long long 
#define ln endl
using namespace std ; 

struct node {
	ll val ;
	node* rp = NULL ;
	node* lp = NULL ;
	node* par = NULL ;
	ll h = 0 ;
	node(ll x ) : val(x) {}
} ;


class BST {
private :
public :	
	node* head = NULL ;
	void insert(ll x){
		node* n = new node(x) ;
		if (head ==NULL){
			head = n ; 
			return ;
		}
		node* tem = head ;
		while(true){
			if (n->val > tem->val){
				if (tem->rp == NULL){
					tem -> rp = n ;
					n -> par = tem ; 
					updateHeight(n) ;
					return ; 
				}
				else {
					tem = tem -> rp ;
				}
			}
			else {
				if (tem -> lp == NULL){
					tem -> lp = n  ;
					n -> par = tem ; 
					updateHeight(n) ;
					return ;
				}
				else {
					tem = tem -> lp ;
				}
			}
		}
	}
	void updateHeight(node* n){
		ll x = 0  ;
		while(n->par!=NULL and n->par->h < x+1){
			n -> par -> h = x+1 ;
			n  = n -> par ; 
			x++ ;
		}
	}
	ll height(node* n){
		if (n ==NULL){
			return 0  ;
		}
		return n->h ;
	}
	ll balance_factor(node* n){
		return height(n->lp) - height(n->rp) ;
	}
	void inorder(node* n){
		if (n == NULL){
			return ;
		}
		inorder(n->lp) ;
		cout << n -> val << "(" << n->h << ") " ;
		inorder(n->rp) ;  
	}	
} ;
int main(){	
	BST bst ;
	ll x ;
	while(true){
		cin >> x ; if (x==-1) exit(0) ;
		bst.insert(x) ;
		bst.inorder(bst.head) ;
		cout << ln ;
	}
	return 0 ;
}

