#include <iostream>
#include "login.h"
#include "print.h"
using namespace std;

int main()
{
	ifstream open("Login_student.txt", ios_base::trunc);
	open.close();
	screen();
}