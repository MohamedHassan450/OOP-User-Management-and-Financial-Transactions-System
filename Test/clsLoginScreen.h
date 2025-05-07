#pragma once
#include<iostream>


#include"clsUser.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"Globel.h"

using namespace std;

class clsLoginScreen:protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFaild = false;
		short Counter = 3;
		do
		{
			system("cls");
			_DrawMainScreenHeader("Login");
			cout << endl;
			cout << "You have " << Counter << " Tries to login " << endl;
			cout << endl;
			if(Counter == 0 )
			{
				system("cls");
				cout << "Access failed try again later" << endl;
				
				exit(0);
			
			}

			if(LoginFaild)
			{
				cout << "Wrong user name or password please try again" << endl;
			}
			string UserName;
			cout << "Enter User Name ? ";
			UserName = clsInputValidate::ReadString();

			string Password;
			cout << "Enter Password ? ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			Counter--;


		} while (LoginFaild );;

		clsUser::SaveInLoginRegisterFile(CurrentUser);
		clsMainScreen::ShowMainMenu();
	

	}

public:

	static void ShowLoginScreen()
	{
		_DrawMainScreenHeader("Login");
		_Login();
	}
};

