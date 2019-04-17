#include "admin.h"
#include "user.h"
#include "camp_equipment.h"
#include "loanControl.h"
#include "filehandler.h"
#include <iostream>
#include <string>
#include <fstream>
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
		cout << "3.) Sub-menu for New USers" << endl;
		cout << "4.) Return Service" << endl;
		cout << "5.) Exit" << endl;
		cout << endl;
		cout << "Select your option number" << endl;
		cin >> option;
	} while (option < 1 || option > 5);
	return option;
}

int main(){
	Admin admin;
	fileHandler fh;

	int option = getMenuOption();

	cout << "Welcome to use our Camp Equipment Loan Services!" << endl;
	
	while (option != 5) {
		string UserId, password;
		string Usertype = Usertype.substr(0, 3);

		cout << "Enter your UserId: ";
		cin >> UserId;

		cout << "Enter your password: ";
		cin >> password;
		User *user = fh.createUser(UserId);
		if (fh.login(UserId, password)) { // call function to check the identity 
			switch (option) 
			{
			case 1:
				fh.displayEquipmentList();
				break;
			case 2:
				admin.displayLoanRecord(user->getName());
				break;
			case 3:
				admin.makeLoan(user);
				break;
			case 4:
				admin.returnEquipments(user);
				break;
			case 5:
				cout << "Thank you for using our services!" << endl;
				break;
			}
			
		
		}
		else {
			cout << "Error! Invalid input! Please try again!" << endl;
			break;
		}
		
	}
	system("pause");
	return 0;
}