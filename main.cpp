#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student {
protected:
	string first_name;
	string last_name;
	double gpa;
	int grad_year;
	string grad_semester;
	int enroll_year;
	string enroll_semester;
	string grad_status;
public:
	Student() {
		this->first_name = "first_name";
		this->last_name = "last_name";
		this->gpa = 0.0;
		this->grad_year = 2000;
		this->grad_semester = "grad_semester";
		this->enroll_year = 2000;
		this->enroll_semester = "enroll_semester";
		this->grad_status = "grad_status";
	}

	~Student() = default;
	
	string getfirst() const { return first_name; }
	string getlast() const { return last_name; }
	double getgpa() const { return gpa; }
	int getgradyear() const { return grad_year; }
	string getgradsem() const { return grad_semester; }
	int getenrollyear() const { return enroll_year; }
	string getenrollsem() const { return enroll_semester; }
	string getgradstat() const { return grad_status; }

	void studentsetter(string first, string last, double sgpa, int gradyear, string gradsem, int enrollyear,
		string enrollsem, string gradstat) {
		this->first_name = first;
		this->last_name = last;
		this->gpa = sgpa;
		this->grad_year = gradyear;
		this->grad_semester = gradsem;
		this->enroll_year = enrollyear;
		this->enroll_semester = enrollsem;
		this->grad_status = gradstat;
	}

	friend ostream& operator << (ostream& os, const Student& student) {
		os << student.first_name << " " << student.last_name << " " << student.gpa << " " << 
			student.grad_year << " " << student.grad_semester << " " << student.enroll_year << " " << 
			student.enroll_semester << " " << student.grad_status;
		return os;
	}
};

class Art_Student : public Student {
	string art_emphasis;
public:
	Art_Student() {
		this->first_name = "first_name";
		this->last_name = "last_name";
		this->gpa = 0.0;
		this->grad_year = 2000;
		this->grad_semester = "grad_semester";
		this->enroll_year = 2000;
		this->enroll_semester = "enroll_semester";
		this->grad_status = "grad_status";
		this->art_emphasis = "art_emphasis";
	}

	~Art_Student() = default;

	string getemp() {
		return art_emphasis;
	}

	void setemp(string emp) {
		this->art_emphasis = emp;
	}

	friend ostream& operator << (ostream& os, const Art_Student& student) {
		os << static_cast<const Student&>(student) << " " << student.art_emphasis;
		return os;
	}
};

class Physics_Student : public Student {
	string concentration;
public:
	Physics_Student() {
		this->first_name = "first_name";
		this->last_name = "last_name";
		this->gpa = 0.0;
		this->grad_year = 2000;
		this->grad_semester = "grad_semester";
		this->enroll_year = 2000;
		this->enroll_semester = "enroll_semester";
		this->grad_status = "grad_status";
		this->concentration = "concentration";
	}

	~Physics_Student() = default;

	string getcon() {
		return concentration;
	}

	void setcon(string con) {
		this->concentration = con;
	}

	friend ostream& operator<<(ostream& os, const Physics_Student& student) {
		os << static_cast<const Student&>(student) << " " << student.concentration;
		return os;
	}
};

int main() {
	vector <Art_Student*> art_students;
	vector <Physics_Student*> physics_students;

	for (int i = 0; i < 5; ++i) {
		art_students.push_back(new Art_Student());
		physics_students.push_back(new Physics_Student());
	}

	art_students[0]->studentsetter("John", "Doe", 3.1, 2027, "Spring", 2023, "Fall", "Undergrad");
	art_students[0]->setemp("Art History");
	art_students[1]->studentsetter("Jane", "Doe", 3.6, 2027, "Spring", 2023, "Fall", "Undergrad");
	art_students[1]->setemp("Art History");
	art_students[2]->studentsetter("Harry", "Mason", 3.4, 2024, "Spring", 2020, "Fall", "Grad");
	art_students[2]->setemp("Art Studio");
	art_students[3]->studentsetter("Zack", "Fair", 2.9, 2026, "Spring", 2022, "Fall", "Undergrad");
	art_students[3]->setemp("Art Studio");
	art_students[4]->studentsetter("Haruka", "Sawamura", 3.9, 2028, "Spring", 2024, "Fall", "Grad");
	art_students[4]->setemp("Art Education");

	physics_students[0]->studentsetter("Cheryl", "Mason", 3.0, 2027, "Spring", 2023, "Fall", "Undergrad");
	physics_students[0]->setcon("Earth and Planetary Sciences");
	physics_students[1]->studentsetter("Maria", "Robotnik", 2.9, 2028, "Spring", 2024, "Fall", "Grad");
	physics_students[1]->setcon("Biophysics");
	physics_students[2]->studentsetter("Barrett", "Wallace", 2.5, 2024, "Spring", 2020, "Fall", "Undergrad");
	physics_students[2]->setcon("Earth and Planetary Sciences");
	physics_students[3]->studentsetter("Kazuma", "Kiryu", 3.2, 2024, "Spring", 2020, "Fall", "Undergrad");
	physics_students[3]->setcon("Earth and Planetary Sciences");
	physics_students[4]->studentsetter("Gordon", "Freeman", 3.9, 2024, "Spring", 2020, "Fall", "Grad");
	physics_students[4]->setcon("Biophysics");

	// Write to file
	ofstream studentfile;
	studentfile.open("student_info.dat");
	for (const auto& student : art_students) {
		studentfile << *student << endl;
	}
	for (const auto& student : physics_students) {
		studentfile << *student << endl;
	}
	studentfile.close();

	for (Art_Student* student : art_students) {
		delete student; 
	} 
	for (Physics_Student* student : physics_students) {
		delete student;
	}

	return 0;
}
