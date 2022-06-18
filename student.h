#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "department.h"
using namespace std;

class student
{
private:
	string studentNUM;
	string studentID;
	string studentPWD;
	string name;
	department department;
	float grade;
	vector<string> subjects;
public:
	student(string id, string pwd, string name, string number, string dp, float grade, vector<string> subjects);
	string getStudentNUM();
	string getStudentID();
	string getStudentNAME();
	string getStudentDepartment();
	vector<string> getStudentSubjects();
};

static vector<student> students;

#endif // !STUDENT_H