#pragma once
#include <iostream>
#include<iomanip>

#include"clsCurrancyExchange.h"


using namespace std;

class clsFindCurrancy: protected clsScreen
{
public:

	static void PrintFindScreen()
	{
		_DrawMainScreenHeader("Find Currancy");
		string CurrancyName;

		cout << "Enter Currancy Name or Code ?";
		CurrancyName = clsInputValidate::ReadString();

		while(!clsCurrancyExchange::IsCurrancyExist(CurrancyName))
		{
			cout << endl;
			cout << "Wrong name or code ,Please try again ?";
			CurrancyName = clsInputValidate::ReadString();
		} 
		cout << endl;
		clsCurrancyExchange Currancy = clsCurrancyExchange::Find(CurrancyName);
		Currancy.PrintCurrancyinfo();
	}

};

