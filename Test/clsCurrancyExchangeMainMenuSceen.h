#pragma once
#include <iostream>
#include<iomanip>

#include"clsCurrancyExchange.h"
#include"clsFindCurrancy.h"
#include"clsCurrancyListSceen.h"
#include"clsCurrancyCalculatorScreen.h"

using namespace std;

class clsCurrancyExchangeMainMenuSceen:protected clsScreen
{
private:

	static void _GoBackToCurrancyExchange()
	{
		cout << endl;
		cout << "Press any key to go back to main menu..........." << endl;
		system("pause>0");
		system("cls");
		PrintCurranyExchangeScreen();

	}

	static enum _eCurrancyExchangeOptions { _eCurrancyList = 1, _eFindCurrancy = 2, _eCurrancyCalculater = 3, _eMainMenu = 4 };

	static void _CurrancyListMainScreen()
	{
		clsCurrancyListSceen::PrintCurrancyListScreen();
		system("pause>0");
	}
	static void _FindCurrancyMainScreen()
	{
		clsFindCurrancy::PrintFindScreen();
		
	}
	static void _UpdateRateMainScreen()
	{
		cout << "Here Will Be UpdateRate" << endl;
		system("pause>0");
	}
	static void _CurrancyCalculaterMainScreen()
	{
		clsCurrancyCalculatorScreen::PrintCurrancyCalculator();
		system("pause>0");
	}

	static int _ReadNumber()
	{
		int Num;
		Num = clsInputValidate::ReadIntNumberBetween(1, 4);
		return Num;
	}

	static void _ChooseOption(_eCurrancyExchangeOptions Option)
	{
		switch (Option)
		{
		case _eCurrancyExchangeOptions::_eCurrancyList:
			{
			system("cls");
			_CurrancyListMainScreen();
			_GoBackToCurrancyExchange();
			}

		case _eCurrancyExchangeOptions::_eFindCurrancy:
			{
				system("cls");
				_FindCurrancyMainScreen();
				_GoBackToCurrancyExchange();
			}



		case _eCurrancyExchangeOptions::_eCurrancyCalculater:
			{
				system("cls");
				_CurrancyCalculaterMainScreen();
				_GoBackToCurrancyExchange();
			}
		case _eCurrancyExchangeOptions::_eMainMenu:
			{
			system("cls");
			cout << "Go Back to Main Menu" << endl;
			}
		}
	}

public:

	static void PrintCurranyExchangeScreen()
	{
		if (!CheckAcssesRight(clsUser::enPermissions::enpCurrancyExchange))
		{
			return;

		}

		_DrawMainScreenHeader("Currancy Exchange Screen");

		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "Currancy Exchange" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t[1]Currancy List" << endl;
		cout << "\t\t\t[2]Find Currancy" << endl;
		cout << "\t\t\t[3]Currancy Calculater" << endl;
		cout << "\t\t\t[4]Main Menu" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\tEnter Number Between [1] To [4] ? ";

		_ChooseOption((_eCurrancyExchangeOptions)_ReadNumber());

	}
};

