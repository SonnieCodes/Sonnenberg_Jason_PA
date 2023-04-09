#pragma once
#include "student.h"

//Building the Roster class
class Roster
{
public:
	//Dynamic array to hold student objects
	vector<Student*> classRosterArray;
		
	//Setters
	void add(string studentID,
		string firstName, string lastName,
		string emailAddress, int age,
		int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);

	void remove(string studentID);

	//Print Fuctions
	void printAll() const;
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	
	//Constructor
	Roster();

	//Destructor
	~Roster();
};