#pragma once
#include <iostream>
#include<iomanip>

#include"clsUser.h"
#include"clsInputValidate.h";

using namespace std;

class clsFindUserScreen:protected clsScreen
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

	static void FindUserScreen()
	{
		_DrawMainScreenHeader("Find User Screen");

		string UserName;
		cout << " Enter User Name ? ";

		UserName = clsInputValidate::ReadString();

		if(!(clsUser::IsUserExist(UserName)))
		{
			cout << "User not found ? Enter User Name ? ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = User.Find(UserName);
		_PrintUserInfo(User);
	}
};

