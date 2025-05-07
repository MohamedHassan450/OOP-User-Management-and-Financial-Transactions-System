#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUserListScreen.h"
#include"clsAddNewUser.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"



using namespace std;

class clsManageUser:protected clsScreen
{
private:


	enum _eUserOptions { _eUserList = 1, _eAddUser = 2, _eDeleteUser = 3, _eUpdateUser = 4, _eFindUser = 5, _eMainMenu = 6 };
	
	static void _GoBackToMangeUserScreen()
	{
		system("pause>0");
		cout << "Press any key to go back to user menu screen ............ " << endl;
		PrintManageUserMainMenu();
	}

	static short _ReadNumberForOptions()
	{
		short Number;

		Number = clsInputValidate::ReadIntNumberBetween(1, 6, "Number is not within range,Enter number between [1] To [6] ? ");

		return Number;

	}

	static void _UserListScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}
	static void _AddUserScreen()
	{
		clsAddNewUser::AddNewUserScreen();
	}
	static void _DeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUserScreen();
	}
	static void _UpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _FindUserScreen()
	{
		clsFindUserScreen::FindUserScreen();
	}

	static void _ChooseFromUserOptions(_eUserOptions Choose) 
	{
		switch(Choose)
		{

		case _eUserOptions::_eUserList:
		{
			system("cls");
			_UserListScreen();
			_GoBackToMangeUserScreen();
			break;

		}

		case _eUserOptions::_eAddUser:
		{
			system("cls");
			_AddUserScreen();
			_GoBackToMangeUserScreen();
			break;

		}

		case _eUserOptions::_eDeleteUser:
		{
			system("cls");
			_DeleteUserScreen();
			_GoBackToMangeUserScreen();
			break;

		}

		case _eUserOptions::_eUpdateUser:
		{
			system("cls");
			_UpdateUserScreen();
			_GoBackToMangeUserScreen();
			break;

		}

		case _eUserOptions::_eFindUser:
		{
			system("cls");
			_FindUserScreen();
			_GoBackToMangeUserScreen();
			break;

		}

		case _eUserOptions::_eMainMenu:
		{
			
		}


		}
	}

public:

	static void PrintManageUserMainMenu()
	{
		if (!CheckAcssesRight(clsUser::enPermissions::enpMangeuser))
		{
			return;

		}

		system("cls");
		_DrawMainScreenHeader("Manage Users Screen");

		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "Manage Users " << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t[1]User List" << endl;
		cout << "\t\t\t[2]Add New User" << endl;
		cout << "\t\t\t[3]Delete User" << endl;
		cout << "\t\t\t[4]Update User" << endl;
		cout << "\t\t\t[5]Find User" << endl;
		cout << "\t\t\t[6]Main Menu" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\tEnter number between [1] to [6] ?" << endl;

		_ChooseFromUserOptions((_eUserOptions)_ReadNumberForOptions());
		
	}

};

