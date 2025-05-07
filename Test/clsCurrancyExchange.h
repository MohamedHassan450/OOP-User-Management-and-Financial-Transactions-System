#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

#include "clsString.h"


using namespace std;

class clsCurrancyExchange
{
private:


	enum _eMode { _eEmpty = 0, _eUpdate = 1 };
	_eMode _Mode;

	string _Country;
	string _CountryCode;
	string _CurrancyName;
	float _Rate;

	static clsCurrancyExchange _ConvertLineReadedFromFile(string Line)
	{
		vector <string> Info = clsString::Split(Line, "#//#");
		
		return clsCurrancyExchange(_eMode::_eUpdate, Info[0], Info[1], Info[2], stof(Info[3]));
	}
	static vector <clsCurrancyExchange> _ReadFromFileCurrencies()
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		vector <clsCurrancyExchange> SaveFromRead;

		if(MyFile.is_open())
		{
			string Line;
			
			while(getline(MyFile,Line))
			{
				clsCurrancyExchange SaveInfo = _ConvertLineReadedFromFile(Line);
				SaveFromRead.push_back(SaveInfo);
			}

			
		}MyFile.close();

		return SaveFromRead;
	}

	 static clsCurrancyExchange GetEmpty()
	 {
		 return clsCurrancyExchange(_eMode::_eEmpty, "", "", "", 0);
	 }



public:
	
	clsCurrancyExchange(_eMode Mode,string Country, string CountryCode, string CurrancyName, float Rate)
	{
		_Country = Country;
		_CountryCode = CountryCode;
		_CurrancyName = CurrancyName;
		_Rate = Rate;
		_Mode = Mode;
	}

	 string GetCountryName()
	{
		return _Country;
	}
	 string GetCountryCode()
	{
		return _CountryCode;
	}
	 string GetCurrancyName()
	 {


		 return _CurrancyName;
	 }
	 float GetRate()
	 {
		 return _Rate;
	 };


	 bool IsEmpty()
	 {
		 return (_Mode == _eMode::_eEmpty);
	 }
	
	 static bool IsCurrancyExist(string CurrancyName)
	 {

		  clsCurrancyExchange Use = clsCurrancyExchange::Find(CurrancyName);
		 return (!Use.IsEmpty());
	 }

	void PrintCurrancyinfo()
	 {
		cout << "============================" << endl;
		cout << "============================" << endl;
		cout << "Currancy Info : " << endl;
		cout << "============================" << endl;
		cout << "============================" << endl;
		cout << "Country         : " << _Country << endl;
		cout << "Country Code    : " << _CountryCode << endl;
		cout << "Currancy Name   : " << _CurrancyName << endl;
		cout << "Rate            : " << _Rate << endl;
	 }

	static clsCurrancyExchange Find(string Country)
	{
		vector<clsCurrancyExchange> Save = _ReadFromFileCurrencies();

		for ( clsCurrancyExchange & C50 : Save) {
			if (C50.GetCountryName() == Country || C50.GetCountryCode() == Country||C50.GetCurrancyName() ==Country )
			{
				return C50;
			}
		}

		return GetEmpty();
	}

	static vector <clsCurrancyExchange> ReadFromFileCurrencies()
	{
		return _ReadFromFileCurrencies();
	}

};

