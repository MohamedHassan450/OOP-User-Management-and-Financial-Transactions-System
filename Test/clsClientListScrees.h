#pragma once
#include <iostream>
#include<iomanip>

#include"clsBankClient.h";



using namespace std;

class clsClientListScrees:protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client)
		{
		

		    cout << "| " << setw(15) << left << Client.AccountNumber();
		    cout << "| " << setw(20) << left << Client.FullName();
		    cout << "| " << setw(12) << left << Client.Phone;
		    cout << "| " << setw(20) << left << Client.Email;
		    cout << "| " << setw(10) << left << Client.PinCode;
		    cout << "| " << setw(12) << left << Client.AccountBalance;
		
		}
public:

	static void ShowClientsList()
		{
		if (!CheckAcssesRight(clsUser::enPermissions::enpShowClientList))
		{
			return;

		}
		    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		
			string Title = "  Client List";
			string SubTitle = "Client Number (" + to_string(vClients.size())+") ";
			clsScreen::_DrawMainScreenHeader(Title, SubTitle);



			cout << "\t\t     =================================================================================================" << endl;
			cout << "\t\t     =================================================================================================" << endl;

			cout << setw(23);
		    cout << "| " << left << setw(15) << "Accout Number";
		    cout << "| " << left << setw(20) << "Client Name";
		    cout << "| " << left << setw(12) << "Phone";
		    cout << "| " << left << setw(20) << "Email";
		    cout << "| " << left << setw(10) << "Pin Code";
		    cout << "| " << left << setw(12) << "Balance";
			cout << endl;
			
			if (vClients.size() == 0) {
				cout << "\t\t\t\tNo Clients Available In the System!";
			}
			else
			{

				cout << "\t\t     =================================================================================================" << endl;

				for (clsBankClient Client : vClients)
				{
					cout << setw(23);
					PrintClientRecordLine(Client);
					cout << endl;
				}

				cout << "\t\t     =================================================================================================" << endl;

			}
		
		}

};

