#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h";



using namespace std;

class clsAddNewClientScreen:protected clsScreen
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

    static void AddClient()
    {
        if (!CheckAcssesRight(clsUser::enPermissions::enpAddNewClient))
        {
            return;

        }

        string Title = "Add New Client ";
        clsScreen::_DrawMainScreenHeader(Title);

        string  AccountNumber;
        cout << "Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "This Account Number Is Already Exsit , Enter Anthor Account Number ? ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult)
        {

        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "Account Add successfully :-) " << endl;
            system("cls");
            NewClient.Print();
            break;
        }

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "Account Not Added :-( " << endl;
            break;

        }

        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "Account Not Added :-( " << endl;
            break;
        }

        }

    }

};

