#pragma once
#include <iostream>
#include<iomanip>

#include"clsUser.h"
#include"clsInputValidate.h";



using namespace std;

class clsAddNewUser:protected clsScreen
{
private:


	static void _ReadUserInfo(clsUser & UserInfo)
	{
		cout << "Enter First Name ? ";
		UserInfo.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name ? ";
		UserInfo.LastName = clsInputValidate::ReadString();

		cout << "Enter Email ? ";
		UserInfo.Email = clsInputValidate::ReadString();

		cout << "Enter Phone ? ";
		UserInfo.Phone = clsInputValidate::ReadString();

		cout << "Enter Password ? ";
		UserInfo.Password = clsInputValidate::ReadString();
        
        UserInfo.Permissions = _ReadUserPermission();
	}

	static int _ReadUserPermission()
	{
        int Permission = 0;
        char YorN;

        cout << "Permissions: " << endl;
        cout << endl;
        cout << "Do you want to give all permissions? Y/N: ";
        cin >> YorN;
        cout << endl;
        if (YorN == 'y' || YorN == 'Y')
        {
             return Permission = clsUser::enPermissions::enpAll;
             
       
        }


        cout << "Do you want to give permission for Client List? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpShowClientList;
        }

        cout << "Do you want to give permission for Add New Client? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpAddNewClient;
        }

        cout << "Do you want to give permission for Delete Client? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpDeleteClient;
        }

        cout << "Do you want to give permission for Update Client? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpUpdateClient;
        }

        cout << "Do you want to give permission for Find Client? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpFindClient;
        }

        cout << "Do you want to give permission for Transactions? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpTransactionMenu;
        }

        cout << "Do you want to give permission for Manage Users? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpMangeuser;
        }

        cout << "Do you want to give permission for Login Register? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpLoginRegister;
        }

        cout << "Do you want to give permission for Currancy Exchange? Y/N: ";
        cin >> YorN;
        if (YorN == 'y' || YorN == 'Y')
        {
            Permission += clsUser::enPermissions::enpCurrancyExchange;
        }

        return Permission;

	}

	static void _PrintUserInfo(clsUser User)
	{
		cout << endl;
		cout << "=================================" << endl;
		cout << "User Information" << endl;
		cout << "=================================" << endl;
		cout << "User Name    : " << User.UserName << endl;
		cout << "First Name   : " << User.FirstName << endl;
		cout << "Last Name    : " << User.LastName << endl;
		cout << "Email        : " << User.Email << endl;
		cout << "Phone        : " << User.Phone << endl;
		cout << "Permission   : " << User.Permissions << endl;
		cout << "=================================" << endl;




	}

public:

	static void AddNewUserScreen()
	{
		clsScreen::_DrawMainScreenHeader("Add New User Screen");

		string ReadUserName;

		cout << "Enter user name ? ";
		ReadUserName = clsInputValidate::ReadString();

		if(clsUser::IsUserExist(ReadUserName))
		{
			cout << "This user is already exist ,Please enter user name ? ";
			ReadUserName = clsInputValidate::ReadString();
		}

		clsUser UserInfo = clsUser::GetAddNewUserObject(ReadUserName);

		_ReadUserInfo(UserInfo);

        _PrintUserInfo(UserInfo);

        clsUser::enSaveResults eSave;
        eSave = UserInfo.Save();

        switch(eSave)
        {
        case clsUser::enSaveResults::svSucceeded:
            {
            cout << "User Added Sucssfully :-) " << endl;
            break;
            }

        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "Sorry faild to add user :-( " << endl;
            break;

        }

        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "Sorry faild to add user :-( " << endl;
            break;

        }

        }

		
	}
};

