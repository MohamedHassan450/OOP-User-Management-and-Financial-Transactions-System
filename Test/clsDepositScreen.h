#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h";

using namespace std;



class clsDepositScreen:protected clsScreen
{

public:

    static void Deposit()
    {
        clsScreen::_DrawMainScreenHeader("Deposit screen");

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
        cout << "Enter Amount to Deposit ? ";
        cin >> AD;
       
        char YorN;
        cout << "Are you sure you want to deposit this amount ? ";
        cin >> YorN;
        if (YorN==toupper('y'))
        {
            Client1.Depositt(AD);
            cout << endl;
            cout << "Amount Deposit Sucssfully" << endl;
            cout << "Account Balance = " << Client1.AccountBalance << endl;
           
        }else
        {
            cout << "Operation Cancelled" << endl;
        }



    }

};

