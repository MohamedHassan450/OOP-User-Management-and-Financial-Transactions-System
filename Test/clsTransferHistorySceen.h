#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsTransferHistorySceen:protected clsScreen
{
private:

	static void _PrintInfo(clsBankClient::_sTransferHistoryInfo info)
	{
	
		cout << "                        |" << info._DateAndTime;
		cout <<  "        | " << info._Sender;
		cout <<  "                    | " << info._Receiver;
		cout << "                     | " << info._AmountTrasferd << endl;


	}

public:

	static void PrintTransferHistoryScreen()
	{
		_DrawMainScreenHeader("Trasfers History Screen");

		vector <clsBankClient::_sTransferHistoryInfo> INFO = clsBankClient::ReceiveFromFileTransferHistory();
		
		cout << "\t\t\t=============================================================================================" << endl;
		cout << "\t\t\t=============================================================================================" << endl;
		cout << "\t\t\t\t\t\t\t\tTrasfers History List" << endl;
		cout << "\t\t\t=============================================================================================" << endl;
		cout << "\t\t\t=============================================================================================" << endl;

		cout << "                        | Date & Time" ;
		cout <<  "             | Sender";
		cout <<  "                | Reciver";
		cout <<  "                | Amount " << endl;
		cout << "\t\t\t=============================================================================================" << endl;

		for(clsBankClient::_sTransferHistoryInfo info : INFO)
		{
			_PrintInfo(info);
			

		}
		cout << endl;
		cout << "\t\t\t=============================================================================================" << endl;

		cout << endl;
	}
	
};

