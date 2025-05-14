#include <bits/stdc++.h>
using namespace std;


class element {
private :
	char key ;
	int count ;
public :
	element() {} ;
	element (char k, int c) : key(k) , count(c) {}
	char getKey() {return key;}
	int getCount() {return count;}
	void setKey(const char &k) {key = k;}
	void setCount(const int &c) {count = c;}
} ;

class dictionary {
	element* eptr = new element[10000] ;
	int cnt = 0 ;
public :
	dictionary() {}
	bool hasElement(char key) {
		for (int i = 0; i < cnt; i++) {
			if (eptr[i].getKey() == key) return true ;
		}
		return false ;
	}
	bool addElement(element elm) {
		if (hasElement(elm.getKey()) ) return false  ;
		eptr[cnt++] = elm ;
		return true ;
	}
	bool addElement(char key, int count) {
		if (hasElement(key)) return false  ;
		eptr[cnt++] = element(key, count) ;
		return true ;
	}
	bool removeElement(element elm) {
		if (!hasElement(elm.getKey())) return false  ;
		int pos ;
		for (int i = 0; i < cnt; i++) {
			if (eptr[i].getKey() == elm.getKey()) {
				pos = i  ;
				break ;
			}
		}
		for (int i = pos ; i < cnt - 1; i++) {
			eptr[i] = eptr[i + 1] ;
		}
		cnt-- ;
		return true  ;
	}
	bool removeElement(char key) {
		if (!hasElement(key)) return false  ;
		int pos ;
		for (int i = 0; i < cnt; i++) {
			if (eptr[i].getKey() == key) {
				pos = i  ;
				break ;
			}
		}
		for (int i = pos ; i < cnt - 1; i++) {
			eptr[i] = eptr[i + 1] ;
		}
		cnt-- ;
		return true  ;
	}
	bool increaseCount(char key) {
		if (!hasElement(key)) return false  ;
		for (int i = 0; i < cnt; i++) {
			if (eptr[i].getKey() == key) {eptr[i].setCount( eptr[i].getCount() + 1) ; break ;}
		}
		return true ;
	}
	bool decreaseCount(char key) {
		if (!hasElement(key)) return false  ;
		for (int i = 0; i < cnt; i++) {
			if (eptr[i].getKey() == key) {
				if (eptr[i].getCount() == 0) {
					removeElement(eptr[i].getKey()) ;
					return true  ;
				}
				eptr[i].setCount( eptr[i].getCount() - 1) ;
				break ;
			}
		}
		return true ;
	}
	void printElements() {
		for (int i = 0; i < cnt; i++) {
			cout << "(" << eptr[i].getKey()  << ":"  << eptr[i].getCount() << ")" << "\n" ;
		}
	}
} ;



int main() {
	char addingList[] = "ABACB" ;
	char deleteList[] = "BCCGG" ;
	dictionary dict ;
	for (int i = 0; i < 5; i++) {
		if (!dict.addElement(addingList[i], 1)  ) {
			dict.increaseCount(addingList[i]) ;
		}
	}
	for (int i = 0; i < 5; i++) {
		dict.decreaseCount(deleteList[i]) ;
	}
	dict.printElements() ;
	return 0 ;
}
