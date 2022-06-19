#include "print.h"

int firstScreen()
{
	int menu;

	system("cls");
	cout << "Available Login operations:" << endl;
	cout << "1. Admin Login" << endl;
	cout << "2. Student Login" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Enter menu : ";
	cin >> menu;

	return menu;
}

bool adminLoginScreen()
{
	string id, pwd;

	system("cls");
	cout << "\t - Admin Login Screen - " << endl << endl;
	cout << "      ID : ";
	cin >> id;
	cout << "PASSWORD : ";
	cin >> pwd;

	if (readLogin(mode::admin, id, pwd))
		return true;
	else
	{
		cout << endl << "아이디 혹은 비밀번호가 일치하지 않습니다." << endl;
		Sleep(1000);
		return false;
	}
}

int adminScreen()
{
	int menu;

	system("cls");
	cout << "- Logged in as Admin -" << endl;
	cout << "1. Add Students" << endl;
	cout << "2. Delete Students" << endl;
	cout << "3. View Table" << endl;
	cout << "4. Main Menu" << endl;
	cout << "5. Exit" << endl << endl;
	cout << "Enter menu : ";
	cin >> menu;

	return menu;
}

void addStudentScreen()
{
	while (true)
	{
		float grade;
		string id, pwd, name, dp, subject, number;
		vector<string> subjects;

		system("cls");
		cout << "\t- Add Student Screen -" << endl;
		cout << "\tenter \"stop\" to stop in ID" << endl << endl;
		cout << "        ID : ";
		cin >> id;
		if (id == "stop")
			break;
		cout << "  PASSWORD : ";
		cin >> pwd;
		cout << "      NAME : ";
		cin >> name;
		cout << "    NUMBER : ";
		cin >> number;
		cout << "DEPARTMENT : ";
		cin >> dp;
		cout << "     GRADE : ";
		cin >> grade;
		cout << " - enter until \"stop\"\n  SUBJECTS : ";
		while (true)
		{
			cin >> subject;
			if (subject == "stop")
				break;
			subjects.push_back(subject);
			cout << "             ";
		}

		student temp(id, pwd, name, number, dp, grade, subjects);

		if (addLogin(mode::student, id, pwd))
		{
			students.push_back(temp);
			cout << endl << "학생 등록을 성공하였습니다." << endl;
		}
		else
			cout << endl << "이미 존재하는 아이디입니다." << endl;

		Sleep(1000);
	}
}

void deleteStudentScreen()
{
	string id, pwd;

	system("cls");
	cout << "\t - Delete Student Screen - " << endl << endl;
	cout << "        ID : ";
	cin >> id;
	cout << "  PASSWORD : ";
	cin >> pwd;

	if (deleteLogin(mode::student, id, pwd, students))
		cout << endl << "학생 삭제를 성공했습니다." << endl;
	else
		cout << endl << "존재하지 않는 아이디입니다." << endl;
	system("pause");
}

void studentsViewTable()
{
	system("cls");
	cout << "- Students View Table -" << endl << endl;

	for (int student = 0; student < students.size(); student++)
	{
		cout << "      NAME : " << students[student].getStudentNAME() << endl;
		cout << "    NUMBER : " << students[student].getStudentNUM() << endl;
		cout << "DEPARTMENT : " << students[student].getStudentDepartment() << endl;
		cout << "  SUBJECTS : ";
		for (int subject = 0; subject < students[student].getStudentSubjects().size(); subject++)
		{
			cout << students[student].getStudentSubjects()[subject] << endl;
			cout << "             ";
		}

		cout << endl;
	}
	system("pause");
}

bool studentLoginScreen(string& id)
{
	string pwd;

	system("cls");
	cout << "\tStudent Login Screen" << endl << endl;
	cout << "      ID : ";
	cin >> id;
	cout << "PASSWORD : ";
	cin >> pwd;

	if (readLogin(mode::student, id, pwd))
		return true;
	else
	{
		cout << endl << "아이디 혹은 비밀번호가 일치하지 않습니다." << endl;
		Sleep(1000);
		return false;
	}
}

int studentScreen()
{
	int menu;

	system("cls");
	cout << "- Logged in as Student -" << endl;
	cout << "1. View Table" << endl;
	cout << "2. Main Menu" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Enter menu : ";
	cin >> menu;

	return menu;
}

void studentViewTable(string id)
{
	system("cls");
	cout << "- Student View Table -" << endl << endl;
	for (int student = 0; student < students.size(); student++)
	{
		if (id == students[student].getStudentID())
		{
			cout << "      NAME : " << students[student].getStudentNAME() << endl;
			cout << "    NUMBER : " << students[student].getStudentNUM() << endl;
			cout << "DEPARTMENT : " << students[student].getStudentDepartment() << endl;
			cout << "  SUBJECTS : ";

			for (int subject = 0; subject < students[student].getStudentSubjects().size(); subject++)
			{
				cout << students[student].getStudentSubjects()[subject] << endl;
				cout << "             ";
			}

			break;
		}
	}
	Sleep(5000);
}

void screen()
{
	while (true)
	{
		int menu = firstScreen();
		string id;

		switch (menu)
		{
		case 1:
			if (!adminLoginScreen())
				break;
			while (true)
			{
				int semiMenu = adminScreen();

				switch (semiMenu)
				{
				case 1:
					addStudentScreen();
					break;
				case 2:
					deleteStudentScreen();
					break;
				case 3:
					studentsViewTable();
					break;
				case 4:
					break;
				case 5:
					return;
				}

				if (semiMenu == 4)
					break;
			}
			break;

		case 2:
			if (!studentLoginScreen(id))
				break;
			while (true)
			{
				int semiMenu = studentScreen();

				switch (semiMenu)
				{
				case 1:
					studentViewTable(id);
					break;
				case 2:
					break;
				case 3:
					return;
				}

				if (semiMenu == 2)
					break;
			}
			break;

		case 3:
			return;
		}
	}
}