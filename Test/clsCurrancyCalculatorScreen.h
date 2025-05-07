#pragma once

#include <iostream>
#include<iomanip>

#include"clsCurrancyExchange.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrancyCalculatorScreen:protected clsScreen
{
public:

	static void PrintCurrancyCalculator()
	{
		_DrawMainScreenHeader("Currancy Calculator Screen");

		cout << "Enter Country Name or Country Code or Currancy Name ? " << endl;
		string ReadName;
		ReadName = clsInputValidate::ReadString();

		while(!(clsCurrancyExchange::IsCurrancyExist(ReadName)))
		{
			cout << endl;
			cout << "Please Enter Country Name or Country Code or Currancy Name ? " << endl;
			ReadName = clsInputValidate::ReadString();
		}

		clsCurrancyExchange CurrancyInfo = clsCurrancyExchange::Find(ReadName);

		cout << "Enter Number in Dollar to Calculat ? " << endl;
		int Num;
		cin >> Num;

		int Result;

		Result = Num * CurrancyInfo.GetRate();

		cout << Num << " Dollars = " << Result << " in " << CurrancyInfo.GetCurrancyName() << endl;
	}

};

