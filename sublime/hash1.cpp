#include <bits/stdc++.h>
#define ll long long 
#define ln '\n'
#define vll vector<ll> 
#define ss second
#define ff first 
using namespace std;

void linear(vll &a,ll  n,ll val,ll &sz){	
	ll  ix = (val % n) ;
	if (a[ix]==-1){
		a[ix] = val ; 
		cout << "Inserted : Index-" << ix  << " (L.F=" << (double)++sz/n << ")" << ln ;
		return ;
	}
	else {
		cout << "Collision : Index-" << ix << ln ;
	}
	ll x = 5 , i = 1 ; 
	while(x--){
		if (a[(ix+i)%n]==-1){
			a[(ix+i)%n] = val ;
			cout << "Inserted : Index-" << (ix+i)%n << " (L.F=" << (double)++sz/n << ")" << ln ;
			return ;   
		}
		else {
			cout << "Collision : Index-" << (ix+i)%n << ln ;
		}
		i++ ;
	}
	cout << "Input Abandoned" << ln ;
}
void quadratic(vll &a,ll  n,ll val,ll &sz){
	ll  ix = (val % n) ;
	if (a[ix]==-1){
		a[ix] = val ; 
		cout << "Inserted : Index-" << ix << " (L.F=" << (double)++sz/n << ")" << ln ;
		return ;
	}
	else {
		cout << "Collision : Index-" << ix << ln ;
	}
	ll x = 5 , i = 1 ; 
	while(x--){
		if (a[(ix+i*i)%n]==-1){
			a[(ix+i*i)%n] = val ;
			cout << "Inserted : Index-" << (ix+i*i)%n << " (L.F=" << (double)++sz/n << ")" << ln ;
			return ;   
		}
		else {
			cout << "Collision : Index-" << (ix+i*i)%n << ln ;
		}
		i++ ;
	}
	cout << "Input Abandoned" << ln ;
}
void doublehash(vll &a,ll  n,ll val,ll &sz){
	ll  ix = (val % n) ;
	if (a[ix]==-1){
		a[ix] = val ; 
		cout << "Inserted : Index-" <<  ix << " (L.F=" << (double)++sz/n << ")" << ln ;
		return ;
	}
	else {
		cout << "Collision : Index-" << ix << ln ;
	}
	ll x = 5 , i = 1 ; 
	while(x--){
		if (a[(ix+i*(7-(val%7) ))%n]==-1){
			a[(ix+i*(7-(val%7) ))%n] = val ;
			cout << "Inserted : Index-" << (ix+i*(7-(val%7) ))%n << " (L.F=" << (double)++sz/n << ")" << ln ;
			return ;   
		}
		else {
			cout << "Collision : Index-" << (ix+i*(7-(val%7) ))%n << ln ;
		}
		i++ ;
	}
	cout << "Input Abandoned" << ln ;
}

int main(){
	ll t ,n , q ; cin >> t >> n >> q ; 
	vll a(n,-1) ;
	ll sz = 0  ;
	while(q--){
		ll val ; cin >> val ;
		if (t==1) linear(a,n,val,sz) ;
		else if (t==2) quadratic(a,n,val,sz) ;
		else doublehash(a,n,val,sz) ;
	}
	return 0 ; 
} 