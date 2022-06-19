#include "login.h"

bool addLogin(mode mode, string id, string pwd)
{
	ifstream open;
	if (mode == mode::admin)
		open.open("Login_admin.txt");
	else if (mode == mode::student)
		open.open("Login_student.txt");

	string saved_id, saved_pwd;
	while (!open.eof())
	{
		open >> saved_id >> saved_pwd;
		if (id == saved_id)
		{
			open.close();
			return false;
		}
	}
	open.close();

	ofstream reopen;
	if (mode == mode::admin)
		reopen.open("Login_admin.txt", ios_base::out | ios_base::app);
	else if (mode == mode::student)
		reopen.open("Login_student.txt", ios_base::out | ios_base::app);
	reopen << id << ' ' << pwd << endl;
	reopen.close();
	return true;
}

bool readLogin(mode mode, string id, string pwd)
{
	string saved_id, saved_pwd;
	ifstream open;
	if (mode == mode::admin)
		open.open("Login_admin.txt");
	else if (mode == mode::student)
		open.open("Login_student.txt");

	while (!open.eof())
	{
		open >> saved_id >> saved_pwd;
		if (id == saved_id && pwd == saved_pwd)
		{
			open.close();
			return true;
		}
	}

	open.close();
	return false;
}

bool deleteLogin(mode mode, string id, string pwd, vector<student>& v)
{
	if (mode == mode::student)
	{
		ifstream open("Login_student.txt");

		char c;
		string allText;
		while (!open.eof())
		{
			if (open.get(c))
				allText += c;
		}

		size_t idPos = allText.find(id);
		size_t pwdPos = allText.find(pwd);
		if (idPos != string::npos && pwdPos != string::npos)
		{
			int index = static_cast<int>(idPos);
			string temp;

			temp += allText.substr(0, index);
			temp += allText.substr(index + id.size() + pwd.size() + 2, -1);
			open.close();

			ofstream reopen("Login_student.txt", ios_base::trunc);
			reopen << temp;
			reopen.close();

			for (int i = 0; i < v.size(); i++)
			{
				if (id == v[i].getStudentID())
				{
					v.erase(v.begin() + i);
					return true;
				}
			}
		}
		else
		{
			open.close();
			return false;
		}
	}
}