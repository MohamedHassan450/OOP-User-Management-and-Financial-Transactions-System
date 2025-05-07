#pragma once
#include<iostream>
#include<iomanip>

#include"clsCurrancyExchange.h"

using namespace std;
class clsCurrancyListSceen:protected clsScreen
{
private:

	static void _PrintInfo(clsCurrancyExchange CurranyInfo)
	{

		
		cout << "| " << setw(40) << left << CurranyInfo.GetCountryName();
		cout << "| " << setw(20) << left << CurranyInfo.GetCountryCode();
		cout << "| " << setw(35) << left << CurranyInfo.GetCurrancyName();
		cout << "| " << setw(30) << left << CurranyInfo.GetRate() << endl;
	}

public:
	static void PrintCurrancyListScreen()
	{
		_DrawMainScreenHeader("Currancy List Screen");

		cout << "=================================================================================================================" << endl;
		cout << "=================================================================================================================" << endl;
		cout << "\t\t\t\t\t\t Currancy List" << endl;
		cout << "=================================================================================================================" << endl;
		cout << "=================================================================================================================" << endl;
		cout << "|Country";
		cout << setw(48) << "|Currancy Code";
		cout << setw(22) << "|Currancy Name";
		cout << setw(28) << "|Rate";
		cout << endl;
		cout << "=================================================================================================================" << endl;

		vector <clsCurrancyExchange> Currancy = clsCurrancyExchange::ReadFromFileCurrencies();

		for (clsCurrancyExchange C70:Currancy)
		{
			
			_PrintInfo(C70);
		}
		cout << "=================================================================================================================" << endl;

	}

};

