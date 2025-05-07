#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalance.h"
#include"clsTrasferScreen.h"
#include"clsTransferHistorySceen.h"

using namespace std;

class clsTransactionMenuScreen:protected clsScreen
{
private:

	static void _GoBackToTransactionMainMenuScreen()
	{
		cout << endl;
		cout << "Press any key to go back to main menu..........." << endl;
		system("pause>0");
		PrintTransctionMainMenu();

	}

	enum _eTransactionOptions { eDepsit = 1, eWithDraw = 2, eTottalBalance = 3,eTrasferMonyScreen = 4 ,eTransferHistroy = 5,eMainMenuScreen = 6 };

	static short _ReadNum()
	{
		short Num;

		Num = clsInputValidate::ReadIntNumberBetween(1, 6);

		return Num;
	}

	static void _DepositMainMenuScreen()
	{
		clsDepositScreen::Deposit();
		_GoBackToTransactionMainMenuScreen();
	}
	static void _WithDrawMainMenuScreen()
	{
		clsWithDrawScreen::WithDraw();
		_GoBackToTransactionMainMenuScreen();
	}
	static void _TottalBalanceMainMenuScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
		_GoBackToTransactionMainMenuScreen();
	}	
	static void _TransferMainMenuScreen()
	{
		clsTrasferScreen::DoTrasfer();
		_GoBackToTransactionMainMenuScreen();
	}
	static void _TransferHistoryMainMenuScreen()
	{
		clsTransferHistorySceen::PrintTransferHistoryScreen();
		_GoBackToTransactionMainMenuScreen();
	}

	static void _ChosseOptionFromTransactionMenu(_eTransactionOptions Options)
	{
		switch(Options)
		{

		case _eTransactionOptions::eDepsit:
			{
			system("cls");
			_DepositMainMenuScreen();
			_GoBackToTransactionMainMenuScreen();
			break;
			}

		case _eTransactionOptions::eWithDraw:
		{
			system("cls");
			_WithDrawMainMenuScreen();
			_GoBackToTransactionMainMenuScreen();
			break;
		}

		case _eTransactionOptions::eTottalBalance:
		{
			system("cls");
			_TottalBalanceMainMenuScreen();
			_GoBackToTransactionMainMenuScreen();
			break;
		}

		case _eTransactionOptions::eTrasferMonyScreen:
		{
			system("cls");
			_TransferMainMenuScreen();
			_GoBackToTransactionMainMenuScreen();
			break;
		}

		case _eTransactionOptions::eTransferHistroy:
		{
			system("cls");
			_TransferHistoryMainMenuScreen();
			_GoBackToTransactionMainMenuScreen();
			break;
		}

		case _eTransactionOptions::eMainMenuScreen:
		{
			system("cls");
			cout << "Go Back to Main Menu" << endl;
		}

		}
	}

public:

	static void  PrintTransctionMainMenu()
	{
		if (!CheckAcssesRight(clsUser::enPermissions::enpTransactionMenu))
		{
			return;

		}
		system("cls");
		clsScreen::_DrawMainScreenHeader("Transaction Main Menu");

		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t" << "Transactions" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\t[1]Deposit" << endl;
		cout << "\t\t\t[2]WithDraw" << endl;
		cout << "\t\t\t[3]Total Balance" << endl;
		cout << "\t\t\t[4]Transfer" << endl;
		cout << "\t\t\t[5]Transfer History" << endl;
		cout << "\t\t\t[6]Main Menu" << endl;
		cout << "\t\t\t===========================================================================================" << endl;
		cout << "\t\t\tEnter Number Between [1] To [6] ? ";

		_ChosseOptionFromTransactionMenu( (_eTransactionOptions) _ReadNum());


	}
};

