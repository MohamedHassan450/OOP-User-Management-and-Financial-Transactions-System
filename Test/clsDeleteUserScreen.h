#pragma once
#include <iostream>
#include<iomanip>

#include"clsUser.h";
#include"clsInputValidate.h";

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUserInfo(clsUser User)
	{
		cout << endl;
		cout << "=================================" << endl;
		cout << "User Information" << endl;
		cout << "=================================" << endl;
		cout << "User Name    : " << User.UserName << endl;
		cout << "First Name   : " << User.FirstName << endl;
		cout << "Last Name    : " << User.LastName << endl;
		cout << "Email        : " << User.Email << endl;
		cout << "Phone        : " << User.Phone << endl;
		cout << "Permission   : " << User.Permissions << endl;
		cout << "=================================" << endl;

	}
public:
	static void DeleteUserScreen()
	{
		cout << "Enter User Name ? " << endl;
		string UserName;
		UserName = clsInputValidate::ReadString();

		if(!(clsUser::IsUserExist(UserName)))
		{
			cout << "User is not exist ? Enter User Name ? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUserInfo(User);

		cout << endl;

		char YorN;
		cout << "Are sure you want to delete user ? Y or N ?" << endl;
		cin >> YorN;

		if (YorN == toupper('y'))
		{
			if(User.Delete())
			{
				cout << "User Deleted sucssfuly" << endl;
			}
			else
			{
				cout << "Faild to delete user " <<endl;
			}
		}
		else
		{
			cout << "Operation cacelled" << endl;
		}
		
	}
};

