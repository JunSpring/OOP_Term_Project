#include "student.h"

student::student(string id, string pwd, string name, string number, string dp, float grade, vector<string> subjects)
{
	this->studentID = id;
	this->studentPWD = pwd;
	this->studentNUM = number;
	this->name = name;
	this->grade = grade;

	for (int i = 0; i < subjects.size(); i++)
		this->subjects.push_back(subjects[i]);

	if (dp == "EcalE")
		this->department = dp::EcalE;
	else if (dp == "EnicsE")
		this->department = dp::EnicsE;
	else if (dp == "ICE")
		this->department = dp::ICE;
	else if (dp == "CE")
		this->department = dp::CE;
	else if (dp == "CS")
		this->department = dp::CS;
	else if (dp == "IRE")
		this->department = dp::IRE;
}

string student::getStudentNUM()
{
	return studentNUM;
}

string student::getStudentID()
{
	return studentID;
}

string student::getStudentNAME()
{
	return name;
}

string student::getStudentDepartment()
{
	if (department == dp::EcalE)
		return "EcalE";
	else if (department == dp::EnicsE)
		return "EnicsE";
	else if (department == dp::ICE)
		return "ICE";
	else if (department == dp::CE)
		return "CE";
	else if (department == dp::CS)
		return "CS";
	else if (department == dp::IRE)
		return "IRE";
}

vector<string> student::getStudentSubjects()
{
	return subjects;
}