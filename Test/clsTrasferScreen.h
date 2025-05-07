#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h";

using namespace std;

class clsTrasferScreen:protected clsScreen
{
private:
	static bool _AmountToTrasfer(clsBankClient Compare,int AmountDeposit)
	{
		
		return (AmountDeposit <= Compare.AccountBalance) ? true : false;
	}
public:
	static void DoTrasfer()
	{
		_DrawMainScreenHeader("Transfer Screen");
		cout << "Enter account name to trasfer from ? ";
		string AccountName = clsInputValidate::ReadString();
		while(!clsBankClient::IsClientExist(AccountName))
		{
			cout << "Wrong Account Name ,Enter account name to trasfer from ? ";
			string AccountName = clsInputValidate::ReadString();
		}
		clsBankClient ClientFrom = clsBankClient::Find(AccountName);
		cout << endl;
		ClientFrom.Print();

		cout << endl;
		cout << "Enter account name to trasfer To ? ";
		string AccountName2 = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountName2))
		{
			cout << "Wrong Account Name ,Enter account name to trasfer to ? ";
			string AccountName = clsInputValidate::ReadString();
		}
		clsBankClient ClientTo = clsBankClient::Find(AccountName2);
		cout << endl;
		ClientTo.Print();

		cout << endl;
		cout << "Enter amount to trasfer to " << ClientTo.FullName()<<" ? " ;
		int AmountDeposit;
		cin >> AmountDeposit;

		if(_AmountToTrasfer(ClientFrom,AmountDeposit))
		{
			ClientTo.Depositt(AmountDeposit);
			ClientFrom.WithDraww(AmountDeposit);
			cout << endl;
			cout << "Amount Transfered Sucssfully :-)";
			cout << endl;

			string SendToFile;
			SendToFile = ClientFrom.AccountNumber() + "#//#" + ClientTo.AccountNumber() + "#//#" + to_string(AmountDeposit);
			clsBankClient::AddToFileTransfer(SendToFile);
			
		}
		else
		{
			cout << "Amount doesn't transferd :-( " << endl;
		}
	}
};

