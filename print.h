#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include <Windows.h>
#include "login.h"
#include "student.h"
using namespace std;

int firstScreen();
bool adminLoginScreen();
int adminScreen();
void addStudentScreen();
void deleteStudentScreen();
void studentsViewTable();
bool studentLoginScreen(string& id);
int studentScreen();
void studentViewTable(string id);
void screen();

#endif // !PRINT_H