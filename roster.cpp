#include "roster.h"

void Roster::add(string studentID, string firstName,
	string lastName, string emailAddress, 
	int age, int daysInCourse1, 
	int daysInCourse2, int daysInCourse3, 
	DegreeProgram degreeProgram)
{
	vector<int> totalAllDays{ daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* addStudent = new Student(studentID, firstName, lastName, emailAddress, age, totalAllDays, degreeProgram);
	classRosterArray.push_back(addStudent);
}
void Roster::remove(string studentID) {
	bool foundID = false;
	cout << "Deleting student ID " << studentID << " from database." << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getstudentID()) {
			cout << " Removed Student: " << studentID << endl;
			classRosterArray.erase(classRosterArray.begin() + i);
			foundID = true;
		}
	}
	if (!foundID) {
		cout << "No student with that ID found" << endl;
	}
 }

//Print Functions
void Roster::printAverageDaysInCourse(string studentID) {
	bool foundID = false;
	int averageDays = 0;
	cout << "The aerage days in course for student #" << studentID << " is: ";
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getstudentID()) {
			vector<int> averageDaysVector = classRosterArray.at(i)->getdaysInCourse();
				for (int i = 0; i < averageDaysVector.size(); i++) {
				averageDays = averageDays + averageDaysVector.at(i);
			}
			cout << averageDays / averageDaysVector.size() << endl;
			foundID = true;
		}
	}
	if (!foundID) {
		cout << "No students found with that ID" << endl;
	}
}
void Roster::printAll() const {
	cout << " Printing Student List " << endl << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		classRosterArray.at(i)->Print(printByColumn::EVERYTHING);
	}
	cout << endl;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	bool foundID = false;
	cout << " Printing all students in the " << degreeProgramStrings[(int)degreeProgram] << " program:" << endl << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		if (degreeProgram == classRosterArray.at(i)->getdegreeProgram()) {
			classRosterArray.at(i)->Print(printByColumn::EVERYTHING);
		}
		foundID = true;
	}
	cout << endl;
	if (!foundID) {
		cout << "No students found in that program" << endl;
	}
}
void Roster::printInvalidEmails() {
	bool foundID = false;
	cout << "Invalid Emails: " << endl << endl;
	for (int i = 0; i < classRosterArray.size(); i++) {
		const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(classRosterArray.at(i)->getemailAddress(), emailPattern)) {
			cout << "Invalid Email for student # " << classRosterArray.at(i)->getstudentID() << " " << classRosterArray.at(i)->getemailAddress() << endl;
			foundID = true;
		}
	}
	if (!foundID) {
		cout << "No invalid emails found." << endl << endl;
	}
	cout << endl;
}

//Constructor
Roster::Roster() {
	return;
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < classRosterArray.size(); i++) {
	delete classRosterArray.at(i);
	}
	return;
}