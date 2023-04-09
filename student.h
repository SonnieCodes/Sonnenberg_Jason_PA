#pragma once
#include "degree.h"

enum class printByColumn {STUDENTID, STUDENTFIRSTNAME, STUDENTLASTNAME, STUDENTEMAIL, STUDENTAGE, STUDENTPROGRAM, CLASSDAYS, EVERYTHING};

//Building Student class
class Student
{
private:
	//Class variables
	string studentID, firstName, lastName, emailAddress;
	int age;
	vector<int> daysInCourse;
	DegreeProgram degreeProgram;

public:
	//Constructor with default values
	Student(
		string studentID = "NONE",
		string firstName = "NONE",
		string lastName = "NONE",
		string emailAddress = "NONE",
		int age = 0,
		vector<int> daysInCourse = {0,0,0},
		DegreeProgram degreeProgram = DegreeProgram::UNDECIDED
	);

	//Getters
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	vector<int> getdaysInCourse();
	DegreeProgram getdegreeProgram();

	//Setters
	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdaysInCourse(vector<int> daysInCourse);
	void setdegreeProgram(DegreeProgram degreeProgram);
	
	//Print function
	void Print(printByColumn printItem);
		
	//Destructor
	~Student();


};