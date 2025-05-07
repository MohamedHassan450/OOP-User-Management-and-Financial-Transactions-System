#pragma once

#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h";

using namespace std;

class clsWithDrawScreen:protected clsScreen
{
public:
    static void WithDraw()
    {
        clsScreen::_DrawMainScreenHeader("WithDraw screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        system("cls");
        Client1.Print();

        cout << endl;
        double AD;
        cout << "Enter Amount to WithDraw ? ";
        cin >> AD;

        char YorN;
        cout << endl;
        cout << "Are you sure you want to WithDraw this amount ? ";
        cin >> YorN;
        if (YorN == toupper('y'))
        {
            Client1.WithDraww(AD);
            cout << endl;
            cout << "Amount WithDraw Sucssfully" << endl;
            cout << endl;
            cout << "Account Balance = " << Client1.AccountBalance << endl;
        }
        else
        {
            cout << "Operation Cancelled" << endl;
        }



    }
};

