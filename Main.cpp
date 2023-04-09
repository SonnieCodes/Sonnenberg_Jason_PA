#include "roster.h"

Roster inputStudentData(const string studentData[], int numStudents);

int main()
{
	cout << "Scripting and Programming Applications(C867) -- C++ -- Jason Sonnenberg -- 001373464" << endl<< endl;

	//Given input strings + my data
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jason,Sonnenberg,jsonne5@wgu.edu,41,14, 20, 17,SOFTWARE",
	};

	//This will allow easy addition of students later.  Just add to studentData above
	const int numStudents = sizeof(studentData) / sizeof(studentData[0]);
	
	Roster classRoster = inputStudentData(studentData, numStudents);
	
	classRoster.printAll();
	classRoster.printInvalidEmails();

	cout << "Average days in course for all students " << endl << endl;
	for (int i = 0; i < classRoster.classRosterArray.size(); i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray.at(i)->getstudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	classRoster.remove("A3");
	return 0;
}

//Breaking up given strings into individual inputs
Roster inputStudentData(const string studentData[], int numStudents) {
	Roster Roster;

	for (int i = 0; i < numStudents; i++) {
		int rhs = studentData[i].find(",");
		string studentIDInput = studentData[i].substr(0, rhs);
		
		int lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string studentFNameInput = studentData[i].substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string studentLNameInput = studentData[i].substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string studentEmailInput = studentData[i].substr(lhs, rhs - lhs);
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int studentAgeInput = stoi(studentData[i].substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int studentClassDays1Input = stoi(studentData[i].substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int studentClassDays2Input = stoi(studentData[i].substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int studentClassDays3Input = stoi(studentData[i].substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		DegreeProgram degreeProgramInput = DegreeProgram::UNDECIDED;
		string studentProgramInput = studentData[i].substr(lhs, studentData[i].length() - lhs);

		//Error code for the throw, value is errelivent in this situation
		int errorCode = 000;

		try {
			if (studentProgramInput == "SECURITY") {
				degreeProgramInput = DegreeProgram::SECURITY;
			}
			else if (studentProgramInput == "NETWORK") {
				degreeProgramInput = DegreeProgram::NETWORK;
			}
			else if (studentProgramInput == "SOFTWARE") {
				degreeProgramInput = DegreeProgram::SOFTWARE;
			}
			else throw errorCode;
		}
			catch (int erorCode) {
				cout << "Unknown Degree Program" << endl;
			}
			Roster.add(studentIDInput, studentFNameInput, studentLNameInput, studentEmailInput, studentAgeInput, 
				studentClassDays1Input, studentClassDays2Input, studentClassDays3Input, degreeProgramInput);
	}
	return Roster;
}