#pragma once
#include<iostream>
#include"clsInputValidate.h";
#include"clsClientListScrees.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionMenuScreen.h"
#include"clsManageUser.h"
#include"clsCurrancyExchangeMainMenuSceen.h"
#include"clsLoginRegister.h"
#include"Globel.h"


using namespace std;

class clsMainScreen : protected clsScreen
{
private:

static void _GoBackToMainMenu()
	{
		cout << endl;
		cout << "Press any key to go back to main menu..........." << endl;
		system("pause>0");
		ShowMainMenu();

	}

enum _enMainMenuOptions {eShowClientList = 1,eAddNewClient = 2,eDeleteClient=3,eUpdateClient=4,eFindClient=5,eTransactionMenu=6,eManageUser=7,eCurrancyExchange = 8,eLoginRegister=9,eLogout=10};

static short _ReadMainMenuOptions() 
{
	short Number;
	cout << "\t\t\tChosse From [1] To [10] ? ";
	Number = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number Between [1] To [10]");

	return Number;

}

static void _ShowClientListScreen()
{
	
	clsClientListScrees::ShowClientsList();

}
static void _AddNewClientScreen()
{

	clsAddNewClientScreen::AddClient();
}
static void _DeleteClientScreen()
{

	clsDeleteClientScreen::DeleteClient();
}
static void _UpdateClientScreen()
{
	clsUpdateClientScreen::UpdateClient();

}
static void _FindClientScreen()
{

	clsFindClientScreen::ShowFindClientScreen();
}
static void _TransactionMenuScreen()
{

	clsTransactionMenuScreen::PrintTransctionMainMenu();
	system("pause>0");
}
static void _ManageUserScreen()
{

	clsManageUser::PrintManageUserMainMenu();
	system("pause>0");
}
static void _CurrancyExchangeScreen()
{
	clsCurrancyExchangeMainMenuSceen::PrintCurranyExchangeScreen();
	system("pause>0");
}
static void _LoginRegisterScreen()
{
	clsLoginRegister::PrintLoginRegsterList();
	_GoBackToMainMenu();
}
static void _LogoutScreen()
{

	CurrentUser = clsUser::Find("", "");
	system("cls");

}

static void _PerformMainMenuOption(_enMainMenuOptions Option)
{
	switch(Option)
	{
		
	case _enMainMenuOptions::eShowClientList:
	{ 
		system("cls"); 
		_ShowClientListScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eAddNewClient:
	{
		system("cls");
		_AddNewClientScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eDeleteClient:
	{
		system("cls");
		_DeleteClientScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eUpdateClient:
	{
		system("cls");
		_UpdateClientScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eFindClient:
	{
		system("cls");
		_FindClientScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eTransactionMenu:
	{
		system("cls");
		_TransactionMenuScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eManageUser:
	{
		system("cls");
		_ManageUserScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eCurrancyExchange:
	{
		system("cls");
		_CurrancyExchangeScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eLoginRegister:
	{
		system("cls");
		_LoginRegisterScreen();
		_GoBackToMainMenu();
		break;
	}

	case _enMainMenuOptions::eLogout:
	{

		_LogoutScreen();
		break;
	}

	}
}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawMainScreenHeader("Main Screen");

		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "Main Menu" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t[1]Show Client List" << endl;
		cout << "\t\t\t[2]Add New Client" << endl;
		cout << "\t\t\t[3]Delete Client" << endl;
		cout << "\t\t\t[4]Update Client" << endl;
		cout << "\t\t\t[5]Find Client" << endl;
		cout << "\t\t\t[6]Transaction Menu" << endl;
		cout << "\t\t\t[7]Manage User" << endl;
		cout << "\t\t\t[8]Currancy Exchange " << endl;
		cout << "\t\t\t[9]Login Register " << endl;
		cout << "\t\t\t[10]Logout" << endl;
		cout << "\t\t\t===========================================================================================" << endl;

		_PerformMainMenuOption((_enMainMenuOptions)_ReadMainMenuOptions());

	}
};

