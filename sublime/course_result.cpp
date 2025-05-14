#include <bits/stdc++.h>
using namespace std;


class Student ;
class ResultService ;
class CourseResult {
private :
	string code , title ;
	double credit , grade ;
	int sem ;
public :
	CourseResult(string _code, string _title, double _credit, double _grade, int _sem) :
		code(_code) , title(_title) , credit(_credit) , grade(_grade) , sem(_sem) {}

	friend bool cmp(CourseResult &a, CourseResult &b) ;
	friend void generateSemWiseResult(Student s) ;
	friend Student  ;
	friend ResultService ;
} ;

class Student {
	string name , id ;
	int course_cnt ;
	vector<CourseResult> course ;
public :
	Student(string _name, string _id, int _cnt = 0) : name(_name) , id(_id) , course_cnt(_cnt) {}
	void enroll(CourseResult& cr) {
		course.push_back(cr) ;
	}

	friend void generateSemWiseResult(Student s) ;
	friend ResultService ;
	friend bool f(Student &a , Student &b) ;

	double calculateCGPA() {
		double total_cred = 0 ,  total_grade = 0 ;
		for (auto c : course) {
			total_cred += c.grade ;
			total_grade += c.grade * c.credit ;
		}
		return total_grade / total_cred ;
	}
} ;

bool cmp(CourseResult &a, CourseResult &b) {
	return a.sem < b.sem ;
}
void generateSemWiseResult(Student s) {
	sort(s.course.begin(), s.course.end(), cmp) ;
	int curr_sem = s.course[0].sem ;
	double total_grade = 0 , total_cred = 0 , curr_sem_gpa = 0 , curr_sem_cred = 0 ;
	cout << "Student ID :" << s.id << "Student Name : " << s.name << endl ;
	for (auto &c : s.course) {
		if (c.sem != curr_sem) {
			cout << "GPA of " << curr_sem << " is :" << curr_sem_gpa / curr_sem_cred << endl ;
			curr_sem_gpa = 0 ; curr_sem_cred = 0 ;
			curr_sem++ ;
		}
		cout << c.sem << " " << c.code << " " << c.title << " " << c.credit << " " << c.grade << endl ;
		total_grade +=  c.credit * c.grade  ;
		curr_sem_cred += c.credit ; total_cred += c.credit ;
		total_grade +=   c.credit * c.grade ;
	}
	cout << "CGPA of " << curr_sem << " is :" << curr_sem_gpa / curr_sem_cred << endl ;
	cout << "final CGPA :" << total_grade / total_cred << endl ;
}

bool f(Student &a , Student &b) {
	return  a.calculateCGPA() >  b.calculateCGPA() ;
}



class ResultService {
	vector<Student> st ;
public :
	void sortStudent() {
		sort(st.begin(), st.end(), f) ;
	}
	void Store() {
		ofstream of("student.txt") ;
		for (auto &s : st) {
			of << s.name << " " << s.id << " " << s.course_cnt << '\n' ;
			for (auto &cr : s.course) {
				of << cr.code <<  " " << cr.title << " " << cr.credit << " " << cr.grade << " " << cr.sem << '\n' ;
			}
		}
	}
// string code , title ;
// double credit , grade ;
// int sem ;
	void Load() {
		ifstream iff ("student.txt") ;
		string s ;
		while (getline(iff, s)) {
			string name , id ; int course_cnt ;
			stringstream ss(s);
			ss >> name >> id >>  course_cnt ;
			Student st(name, id) ;
			for (int i = 0; i < course_cnt; i++) {
				getline(iff, s) ;
				string code , title ;
				double credit , grade ;
				int sem  ;
				stringstream ss(s) ;
				ss >> code >> title >> credit >> grade >> sem ;
				CourseResult crs(code, title, credit, grade, sem) ;
				st.course.push_back(crs) ;
			}
		}
	}
} ;




int main() {

}