#pragma once

#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h";

using namespace std;

class clsUpdateClientScreen:protected clsScreen
{
private:


	static void ReadClientInfo(clsBankClient& Client)
	{
	    cout << "\nEnter FirstName: ";
	    Client.FirstName = clsInputValidate::ReadString();
	
	    cout << "\nEnter LastName: ";
	    Client.LastName = clsInputValidate::ReadString();
	
	    cout << "\nEnter Email: ";
	    Client.Email = clsInputValidate::ReadString();
	
	    cout << "\nEnter Phone: ";
	    Client.Phone = clsInputValidate::ReadString();
	
	    cout << "\nEnter PinCode: ";
	    Client.PinCode = clsInputValidate::ReadString();
	
	    cout << "\nEnter Account Balance: ";
	    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

public:

    static void UpdateClient()
    {
        if (!CheckAcssesRight(clsUser::enPermissions::enpUpdateClient))
        {
            return;

        }
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";


        ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            system("cls");
            Client1.Print();
            cout << "\nAccount Updated Successfully :-)\n";
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    };

};

