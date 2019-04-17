#include "Filehandler.h"
#include <iostream>
#include <fstream>												//	reserved for the user of fileread and filewrite functions
#include <string>
#include "camp_equipment.h"
#include "User.h"

using namespace std;

Equipment *FileHandler::EquipmentIdentity(string itemCode)
{
	ifstream input;												//	make use of ifstream function 
	int position1, position2;
	int _PurchaseDate;
	string _itemCode, _itemName, _brand, _EquipType, _condition, _status;
	string PurchaseDate;
	string information, info;

	input.clear();												//	initialize by using .clear to delete the past record
	input.open("camp_equipment.txt");							//	use .open function to open the camp_equipment.txt in the corresponding path

	while ( !input && information.length() != 0)				//	set the while-loop to loop through every line of the .txt file until the end of file
	{
		
		if (info.assign(information, 0, 4) == itemCode)			// check for the first 4 characters in camp_equipment.txt , eg) T002 is the correct itemCode
		{

			position1 = 4;
			_itemCode.assign(information, 0, 4);				//	Make sure that the first four digits are itemCode

			position2 = information.find("|", position1 + 1);	//	to match the format of the given .txt (seperated by |)
			_itemName.assign(information, position1 + 1, position2 - position1 - 1);	

			position1 = information.find("|", position2 + 1);
			_brand.assign(information, position2 + 1, position1 - position2 - 1);

			position2 = information.find("|", position1 + 1);
			_EquipType.assign(information, position1 + 1, position2 - position1 - 1);

			position1 = information.find("|", position2 + 1);
			_PurchaseDate = stoi(PurchaseDate.assign(information, position2 + 1, position1 - position2 - 1));

			position2 = information.find("|", position1 + 1);
			_condition.assign(information, position1 + 1, position2 - position1 - 1);

			position1 = information.find("|", position2 + 1);
			_status.assign(information, position2 + 1, position1 - position2 - 1);

			position2 = information.find("|", position1 + 1);
			
			//	dynamic memory declaration to update the information of the campEquipment identity
			Equipment *equipment = new Equipment(_itemCode, _itemName, _brand, _EquipType, _PurchaseDate, _condition, _status);		
			
			input.close();
			return equipment;
		}
	}
	return nullptr;				//	return to null pointer
}

User *FileHandler::UserIdentity(string _UserId)
{
	ifstream input;
	int position1, position2;
	int _DateOfBirth;
	string first3letter, _UserName, _Section, _address, _rank;
	string information, info;
	input.open("user.txt", ios::beg);
	while (!input)							
	{
		getline(input, information);
		if (info.assign(information, 0, 6) == _UserId)			// check for the first 6 characters in user.txt , eg) VEN002 is the correct UserID
			break;
	}
	first3letter = info.assign(information, 0, 3);

	_UserId = info.assign(information, 0, 6);

	position1 = information.find("|", 7);
	_UserName = info.assign(information, 7, position1 - 7);

	position2 = information.find("|", position1 + 1);
	_Section = info.assign(information, position1 + 1, position2 - position1 - 1);

	position1 = information.find("|", position2 + 1);
	_DateOfBirth = stoi(info.assign(information, position2 + 1, position1 - position2 - 1));

	position2 = information.find("|", position1 + 1);
	_address = info.assign(information, position1 + 1, position2 - position1 - 1);


	//	dynamic memory declaration to update the information of various kinds of user identities according to first 3 letters

	
		if (first3letter == "VEN")
		{
			User* user = new VentureScout(_UserId, _UserName, _Section, _DateOfBirth, _address);
			return user;
		}
		else if (first3letter == "ROV")
		{
			User* user = new RoverScout(_UserId, _UserName, _Section, _DateOfBirth, _address);
			return user;
		}
		else
		{
		_rank = info.assign(information, position2 + 1, information.length() - position2 - 1);
		if (first3letter == "SCT")
		{
			User* user = new Scout(_UserId, _UserName, _Section, _DateOfBirth, _address, _rank);
			return user;
		}
		else
		{
			User* user = new Scouter(_UserId, _UserName, _Section, _DateOfBirth, _address, _rank);
			return user;
		}
	}
	return nullptr;
}


//	actually preparation for the 1st option of menu
void FileHandler::displayEquipmentList()
{
	ifstream input;
	int position1, position2;
	string information, info;
	input.open("camp_equipment.txt", ios::beg);
	
	while (!input.eof())				//	set the while-loop to loop through every line of the .txt file until the end of file
	{
		getline(input, information);

		//	match the criteria of the "categorical list"
		if (information.length() != 0)	
		{
			position1 = information.find("|", 5);			//	make use of the .find function to print out the format same as the given .txt file

			position2 = information.find("|", position1 + 1);

			position1 = information.find("|", position2 + 1);

			position2 = information.find("|", position1 + 1);

			position1 = information.find("|", position2 + 1);

			info.assign(information, position2 + 1, position1 - position2 - 1);

			//	only "good" conditions and unborrowed items are on the list
			if (info == "good")
			{
				position2 = information.find("|", position1 + 1);
				info.assign(information, position1 + 1, position2 - position1 - 1);

				if (info == "in")
				{
					info = information.assign(information, 0, 4);
					Equipment *equip = EquipmentIdentity(info);
					equip->displayCommonInfo();
				}
			}
		}
	}
	input.close();			//	close up the input stream and free the memory
}

//	actually preparation for the 2nd option of menu
bool FileHandler::login(string UserId, string password)
{
	ifstream input;
	int position1, position2;
	string information, info;
	input.open("user.txt", ios::beg);
	while (!input.eof())
	{
		getline(input, information);
		if (information.length() == 0)
		{
			getline(input, information);
		}

		position1 = information.find("|", 0);

		position2 = information.find("|", position1 + 1);

		if (info.assign(information, 0, 6) == UserId)	// to check whether the first 6 character is the valid UserId (e.g. VEN001)
		{
			position1 = information.find("|", position2 + 1);

			position2 = information.find("|", position1 + 1);
			if (info.assign(information, position1 + 1, position2 - position1 - 1) == password)		//	set the birthday number be the password
				return true;		
			else return false;		
		}
	}
	return false;
}

//	actually preparation for the 3rd option of menu
void FileHandler::changeLoanStatus(User* user)
{
	ifstream input;
	string information, info;
	int position1, position2, NumofReturned;
	NumofReturned = 0;
	input.open("loan_record.txt", ios::beg);
	while (!input)
	{
		do
		{
		getline(input, information);				
		} 
		while (information.length() == 0);	//	break the while-loop if no information detected

		position1 = information.find("|", 0);

		position2 = information.find("|", position1 + 1);

		position1 = information.find("|", position2 + 1);

		position2 = information.find("|", position1 + 1);

		if ( info.assign(position1 + 1, position2 - position1 - 1) == user->getUserName() )
		{
			position1 = information.find("|", position2 + 1);
			if (info.assign( information, position1 + 1, information.length() - position1 - 2 ) == "returned")		//	check for the status one to see whether returned or not
				NumofReturned--;		
			else NumofReturned++;		
		}
	}
	if (NumofReturned == 0)					//	returned all equipments
		user->setLoanStatus(false);		//	borrowing = false => user can borrow
	
	else
	{
		user->setLoanStatus(true);		//	borrowing = true => user cannot borrow until he/she return all the equipments
		user->setLoanNumber(NumofReturned);	//	To call out the user function to set the MaxLoan
										//	until it reaches its max (e.g. venture scout MAX= 3)
	}
}