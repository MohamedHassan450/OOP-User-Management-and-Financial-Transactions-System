#pragma once
#include<iostream>

#include"clsUser.h"

using namespace std;

class clsLoginRegister:protected clsScreen
{
private:

	static void _Print(clsUser::_sLoginRegster C50)
	{

		cout << "| " << setw(35) << left << C50._sDateAndTime;
		cout << "| " << setw(21) << left <<C50._sUserName;
		cout << "| " << setw(24) << left <<C50._sPassword;
		cout << "| " << setw(30) << left << C50._sPermission << endl;
	}

public:

	static void PrintLoginRegsterList()
	{
		if (!CheckAcssesRight(clsUser::enPermissions::enpLoginRegister))
		{
			return;

		}

		_DrawMainScreenHeader("Login Regstier Screen");

		cout << "==================================================================================================" << endl;
		cout << "==================================================================================================" << endl;
		cout << "\t\t\t\t\tLogin Regster " << endl;
		cout << "==================================================================================================" << endl;
		cout << "==================================================================================================" << endl;
		cout << "|Date & Time";
		cout << setw(35) << "|User Name";
		cout << setw(22) << "|Password";
		cout << setw(28) << "|Permission";
		cout << endl;
		cout << "==================================================================================================" << endl;
		 
		vector <clsUser::_sLoginRegster> Save = clsUser::ReadFromFileLoginRegister();

		for(clsUser::_sLoginRegster C50:Save)
		{
			_Print(C50);
		}

		cout << "==================================================================================================" << endl;

	}

};

