#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";
#include"clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
public:
   static void DeleteClient()
    {
       if (!CheckAcssesRight(clsUser::enPermissions::enpDeleteClient))
       {
           return;

       }
       clsScreen::_DrawMainScreenHeader("Delete Client");
        string AccountNumber;
        cout << "Enter Account Number ? " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account Number isn't Exist ? Enter Account Number  ? " << endl;
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        char YorN;
        cout << "Are you sure you want to delete this client ? Y or N ?" << endl;
        cin >> YorN;

        if (YorN == 'Y' || YorN == 'y')
        {

            if (Client.Delete())
            {
                system("cls");
                Client.Print();
                cout << "Account Deleted successfully" << endl;
            }
            else
            {
                cout << "Account didn't deleted " << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "Deleting Cancelled " << endl;
        }
    };

};

