#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
using namespace std;

enum class mode
{
	admin,
	student
};

bool addLogin(mode mode, string id, string pwd);
bool readLogin(mode mode, string id, string pwd);
bool deleteLogin(mode mode, string id, string pwd, vector<student>& v);

#endif // !LOGIN_H