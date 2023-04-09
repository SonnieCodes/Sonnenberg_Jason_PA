#include "student.h"


Student::Student(
	string studentID, string firstName,
	string lastName, string emailAddress,
	int age, vector<int> daysInCourse,
	DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse = daysInCourse;
	this->degreeProgram = degreeProgram;
	return;
}

//Getter definitions
string Student::getstudentID() { return studentID; }
string Student::getfirstName() { return firstName; }
string Student::getlastName() { return lastName; }
string Student::getemailAddress() { return emailAddress; }
int Student::getage() { return age; }
vector<int> Student::getdaysInCourse() { return daysInCourse; }
DegreeProgram Student::getdegreeProgram() { return degreeProgram; }

//Setter definitions
void Student::setstudentID(string studentID){ this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setage(int age) { this->age = age; }
void Student::setdaysInCourse(vector<int>daysInCourse) { this->daysInCourse = daysInCourse; }
void Student::setdegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Print Function Definitions
void Student::Print(printByColumn printItem) { 
	switch (printItem) {
	case printByColumn::STUDENTID:
		cout << "Student ID: " << studentID << endl;
		break;
	case printByColumn::STUDENTFIRSTNAME:
		cout << " First Name: " << firstName << endl;
		break;
	case printByColumn::STUDENTLASTNAME:
		cout << " Last Name: " << lastName << endl;
		break;
	case printByColumn::STUDENTEMAIL:
		cout << " Email Address: " << emailAddress << endl;
		break;
	case printByColumn::STUDENTAGE:
		cout << " Age: " << age << endl;
		break;
	case printByColumn::CLASSDAYS:
		cout << " Days to Complete Course: " << "{ ";
		for (int i = 0; i < daysInCourse.size(); i++) {
			cout << daysInCourse.at(i);
			if (daysInCourse.size() > i + 1) {
				cout << ", ";
			}
		}
		cout << " }";
		break;
	case printByColumn::STUDENTPROGRAM:
		cout << " Degree Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
		break;
	case printByColumn::EVERYTHING:
		cout << " Student ID: " << studentID << "\t";
		cout << " First Name: " << firstName << "\t";
		cout << " Last Name: " << lastName << "\t";
		cout << " Email Address: " << emailAddress << "\t";
		cout << " Age: " << age << "\t";
		cout << " Days to Complete Course: " << "{ ";
		for (int i = 0; i < daysInCourse.size(); i++) {
			cout << daysInCourse.at(i);
			if (daysInCourse.size() > i + 1) {
				cout << ", ";
			}
		}
		cout << " }";
		cout << " Degree Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
		break;
	}
}

//Destructor
Student::~Student() {}
