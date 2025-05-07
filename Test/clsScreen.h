#pragma 
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"Globel.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
private:
	static void _PrintCurrentDate()
	{
		clsDate Date = clsDate::GetSystemDate();
		cout << "\t\t\t\t\t\t\t     ";
		Date.Print();
	}
protected:

	static void _DrawMainScreenHeader(string Title,string SubTitle = "")
	{
		cout << "\t\t\t-------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t\t\t" << Title << "\t\t" << endl;
		cout << "\t\t\t\t\t\t\t\t" << SubTitle << "\t\t" << endl;
		cout << "\t\t\t-------------------------------------------------------------------------------------------" << endl;

		_PrintCurrentDate();
		cout << "\t\t\t\t\t\t\t     ";
		cout << "User : " << CurrentUser.UserName << endl;
		
		cout << endl;
		cout << endl;
		cout << endl;
	}

	static bool CheckAcssesRight(clsUser::enPermissions Permission)
	{
		if(!CurrentUser.CheckPermission(Permission))
		{
			cout << "\t\t\t-------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t\t\t" << "Access Denied" << "\t\t" << endl;
			cout << "\t\t\t-------------------------------------------------------------------------------------------" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

};

