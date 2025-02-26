#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define ln '\n'
#define ull unsigned  long long
#define ll long long 
#define vll vector<ll>
#define pll pair<ll, ll>
#define ff first
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int> b
#define ld long double
#define ss second
using namespace std;


void setIO(const string io="a"){
    freopen((io+".in").c_str(),"r",stdin) ;
    freopen((io+".out").c_str(),"w",stdout) ;
}


class Book {
private :
    string title , author , ISBN ; 
public :
    Book(string title,string author,string ISBN)
        : title(title) , author(author) , ISBN(ISBN) {}
    string get_title() const {
        return title ;
    }
    string get_author() const {
        return author ;
    }
    string get_ISBN() const {
        return ISBN ;
    }
    void display() const {
        cout << "Title : " << title << ln ;
        cout << "Author : "  << author << ln ;
        cout << "ISBN : " << ISBN << ln ; 
    }
} ;

class Library {
private :
    vector<Book> inventory ; 
    deque<Book> borrowedBooks ; 
    list<Book> archivedBooks ;
public :
    void addBook(){
        string name , author , ISBN ;
        cout << "Enter The Book name : " ; cin >> name ; 
        cout << "Enter the Author name : " ; cin >> author ;
        cout << "Enter the ISBN number : " ; cin >> ISBN ;
        Book b(name,author,ISBN) ;
        inventory.push_back(b) ; 
    } 
    void borrowBook(const string &ISBN) {
        for (auto it=inventory.begin();it!=inventory.end();it++){
            if (it->get_ISBN()==ISBN){
                borrowedBooks.push_back(*it) ;
                inventory.erase(it) ;
                break ;
            }
        }
    }
    void returnBook(const string &ISBN) {
        for (auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            if (it->get_ISBN()==ISBN){
                inventory.push_back(*it) ;
                borrowedBooks.erase(it) ;
                break ;
            }
        }
    }
    void archiveBook(const string &ISBN) {
        for (auto it=inventory.begin();it!=inventory.end();it++){
            if (it->get_ISBN()==ISBN){
                archivedBooks.push_back(*it) ;
                inventory.erase(it) ;
                break ;
            }
        }
    }
    void displayInventory() const {
        for(auto &book:inventory){
            cout << "name : " << book.get_title() << ln ;
            cout << "author : " << book.get_author() << ln ;
            cout << "ISBN : " << book.get_ISBN() << ln ; 
        }
        cout << ln ;
    }
    void displayBorrowed() const {
        for(auto &book:borrowedBooks){
            cout << "name : " << book.get_title() << ln ;
            cout << "author : " << book.get_author() << ln ;
            cout << "ISBN : " << book.get_ISBN() << ln ; 
        }
        cout << ln ;        
    }
    void displayArchived() const {
        for(auto &book:archivedBooks){
            cout << "name : " << book.get_title() << ln ;
            cout << "author : " << book.get_author() << ln ;
            cout << "ISBN : " << book.get_ISBN() << ln ; 
        }
        cout << ln ;
    }
    void saveData(){
        ofstream inv("inventory.txt") ;
        if (!inv){
            cout << "inventory.txt not found ! " << ln ;
        }
        else {
            for(auto &book:inventory){
                inv <<  book.get_title() << "," << book.get_author() <<"," << book.get_ISBN() << ln ;
            }
        }
        inv.close() ;
        ofstream borr("borrowed.txt") ; 
        if (!borr){
            cout << "borrowed.txt not found ! " << ln ;
        }
        else {
            for(auto &book:borrowedBooks){
                borr <<  book.get_title() << "," << book.get_author() <<"," << book.get_ISBN() << ln ;
            }            
        }
        borr.close() ;
        ofstream arc("archived.txt") ;
        if (!arc){
            cout << "archived.txt not found ! " << ln ;
        }
        else {
            for(auto &book:archivedBooks){
                arc <<  book.get_title() << "," << book.get_author() <<"," << book.get_ISBN() << ln ;
            }             
        }
        arc.close() ;
    }
    void loadData() {
        ifstream inv("inventory.txt") ;
        if (!inv){
            cout << "inventory.txt not found ! " << ln ;
        }
        else {
            string s ;
            while(getline(inv,s)){
                string name , author , ISBN ; 
                istringstream iss(s) ; 
                getline(iss,name,',') ; 
                getline(iss,author,',') ;
                getline(iss,ISBN) ;
                Book b(name,author,ISBN) ;
                inventory.push_back(b) ;
            }
        }
        inv.close() ;
        ifstream borr("borrowed.txt") ; 
        if (!borr){
            cout << "borrowed.txt not found ! " << ln ;
        }
        else {
            string s ;
            while(getline(borr,s)){
                string name , author , ISBN ; 
                istringstream iss(s) ; 
                getline(iss,name,',') ; 
                getline(iss,author,',') ;
                getline(iss,ISBN) ;
                Book b(name,author,ISBN) ;
                borrowedBooks.push_back(b) ;
            }
        }
        borr.close() ;
        ifstream arc("archived.txt") ;
        if (!arc){
            cout << "archived.txt not found ! " << ln ;
        }
        else {
            string s ;
            while(getline(arc,s)){
                string name , author , ISBN ; 
                istringstream iss(s) ; 
                getline(iss,name,',') ; 
                getline(iss,author,',') ;
                getline(iss,ISBN) ;
                Book b(name,author,ISBN) ;
                archivedBooks.push_back(b) ;
            }
        }
        arc.close() ;
    }
} ; 


int main(){
    Library lib ; 
    lib.loadData() ;  // can read from file properly 
    //  lib.addBook() ;
    //  lib.addBook() ;
    // lib.loadData() ;
    //lib.borrowBook("b") ;
   // lib.saveData() ;
    lib.displayInventory() ;
    lib.displayBorrowed() ;
    lib.displayArchived() ;
    return 0 ;
}