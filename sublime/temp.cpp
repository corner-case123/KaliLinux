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


void setIO(const string io = "a") {
    freopen("in.txt", "r", stdin) ;
    freopen("out.txt", "w", stdout) ;
}

class Management ;
class Course {
private :
    string title , code , category ;
    int eff_hour , num_section , teach_assigned ;
    friend Management ;
} ;
class Teacher {
private :
    string name , desig ;
    int min_hour , eff_hour ;
    friend Management ;
} ;

class Management {
private :
    vector<Course> cour ;
    vector<Teacher> teach ;
    unordered_map<string, vector<Teacher>> mp ;
public :
    void addCourse(Course& c) {
        cour.push_back(c) ;
    }
    void addTeacher(Teacher& t) {
        teach.push_back(t) ;
    }
    void assignCourse(string course_code, string t_name) {
        Course* cptr = NULL ;
        Teacher* tptr = NULL ;
        for (auto &e : cour) {
            if (e.code == course_code) cptr = &(e) ;
        }
        for (auto &e : teach) {
            if (e.name == t_name) tptr = &(e) ;
        }
        if (cptr == NULL or tptr == NULL) {
            return ;
        }

        int can_assign = (cptr->num_section) ;
        if (cptr->category == "lab") can_assign *= 2;
        can_assign -= cptr->teach_assigned ;

        if (can_assign > 0) {
            mp[cptr->code].push_back(*(tptr)) ;
            cptr -> teach_assigned++ ;
            tptr -> eff_hour += (cptr->eff_hour) ;
        }
    }
    void detachCourse(string course_code, string t_name) {
        for (auto it = mp[course_code].begin(); it != mp[course_code].end(); it++) {
            if (it->name == t_name) {
                mp[course_code].erase(it) ;
                Course* cptr = NULL ;
                Teacher* tptr = NULL ;
                for (auto &e : cour) {
                    if (e.code == course_code) e.teach_assigned-- , cptr = &e ;
                }
                for (auto &e : teach) {
                    if (e.name == t_name) e.eff_hour -= (cptr->eff_hour) ;
                }
            }
            return ;
        }
    }
} ;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); setIO() ;
}