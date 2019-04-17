#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "fileHandler.h"
#include "admin.h"
#include "FileHandler.h"
#include "LoanControl.h"
#include "camp_equipment.h"
using namespace std;


int getMenuOption()
{
	system("cls");
	int option;
	do {
		cout << "Select which service you want..." << endl;
		cout << "--------------------------------" << endl;
		cout << "1.) Categorical List of Available Camp Equipment " << endl;
		cout << "2.) Your Loan Record" << endl;
		cout << "3.) Sub-menu for New Users" << endl;
		cout << "4.) Return Service" << endl;
		cout << "5.) Exit" << endl;
		cout << endl;
		cout << "Select your option number" << endl;
		cin >> option;
	} while (option < 1 || option > 5);
	return option;
}

int getAdminMenuOption()
{
	system("cls");
	int choice;
	do {
			cout << "Select which service you want..." << endl;
			cout << "1. Insert the text files" << endl;
			cout << "2. Display loan record" << endl;
			cout << "3. Display the catrgorical list of camp equipment" << endl;
			cout << "4. Update the condition of equipment" << endl;
			cout << "5. Update data" << endl;
			cout << "6. Exit" << endl;	
			cout << endl;

			cout << "Select your option number" << endl;
			cin >> choice;
	} while (choice < 1 || choice > 6);
	return choice;
}

int main()
{
	string UserId, password;
	admin ADMIN;
	FileHandler fH;
	int option = getMenuOption();
	int choice = getAdminMenuOption();
	cout << "Welcome to use our Camp Equipment Loan Services!" << endl;
	cout << "------------------------------------------------" << endl;
	while (option!=5 || choice !=5)
	{
		cout << "Enter your user-ID: ";
		cin >> UserId;
		cout << "Enter password: ";
		cin >> password;

		if (fH.login(UserId, password))
		{
			
			User *user = fH.UserIdentity(UserId);
			cout << "Hello! " << user->getUserName() << endl;
			
				switch (option)
				{
				case 1:
					fH.displayEquipmentList();
					break;
				case 2:
					ADMIN.displayLoanRecord(user->getUserName());
					break;
				case 3:
					ADMIN.makeLoan(user);
					break;
				case 4:
					ADMIN.returnEquipments(user);
					break;
				case 5:
					cout << "Thanks for using!" << endl;
					system("pause");
					return 0;
					break;
				}
		}
		
			else if (UserId == "admin" && password == "admin") {
				User *user = fH.UserIdentity(UserId);		//	can be the same as the normal user
				cout << "Hello! Admin" << endl;
				switch (choice)
				{
				case 1:
				//fH.displayEquipmentList();
				break;

				case 2:
				ADMIN.displayLoanRecord(user->getUserName());
				break;

				case 3:
				fH.displayEquipmentList();
				break;

				case 4:
				//fH.changeLoanStatus(User* user);
				break;

				case 5:
				

				case 6:
				cout << "Thanks for using!" << endl;
				break;
				}
			}
				
			else cout << "Your account or password was entered incorrectly. Please try again." << endl;	// skip the admin case
	}
	system("pause");
	return 0;
}
