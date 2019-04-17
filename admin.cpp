#include "admin.h"
using namespace std;

void admin::displayLoanRecord(string userName)
{
	ifstream input;
	string information, info;
	int position1, position2, NumofReturned;

	NumofReturned = 0;			// initialize before use

	input.clear();				//	initialize by using .clear to initialize the function
	input.open("loan_record.txt");
	while (!input)				//	in order to loop though all the lines
	{
		getline(input, information);
		if (information.length() == 0)	
			break;

		position1 = information.find("|", 0);

		position2 = information.find("|", position1 + 1);

		position1 = information.find("|", position2 + 1);

		position2 = information.find("|", position1 + 1);

		if (info.assign(information, position1 + 1, position2 - position1 - 1) == userName)
		{
			cout << information << endl;
			NumofReturned++;
		}
	}
	if (NumofReturned == 0)
		cout << "No loan is made yet." << endl;
	
}

void admin::updateEquipmentCondition(string eID, string status)
{
	ifstream input;
	ofstream output;
	input.clear();						//	initialize by using .clear to initialize the function
	output.clear();						//	initialize by using .clear to initialize the function
	string oldInformation, UpdatedInformation, info;
	input.open("camp_equipment.txt");
	output.open("updating.txt");
	
	while (!input)
	{
		getline(input, oldInformation);
		if (oldInformation.length() == 0)
		{

		}
		else
		{
			if (info.assign(oldInformation, 0, 3) == eID)
			{
				
				if (status == "out")
				{
					int pos = oldInformation.find("|in|", 0);
					UpdatedInformation = oldInformation.assign(oldInformation, pos + 3, oldInformation.length() - pos - 4);
					oldInformation = oldInformation.assign(oldInformation, 0, pos);
					oldInformation = oldInformation.append("out");
					oldInformation = oldInformation.append(UpdatedInformation);
				}
				else
				{
					int pos = oldInformation.find("|out|", 0);
					UpdatedInformation = oldInformation.assign(oldInformation, pos + 3, oldInformation.length() - pos - 4);
					oldInformation = oldInformation.assign(oldInformation, 0, pos);
					oldInformation = oldInformation.append("in");
					oldInformation = oldInformation.append(UpdatedInformation);
				}
			}
			output << oldInformation << endl;
		}
	}
	input.close();
	output.close();
	input.open("tmp.txt", ios::beg);
	output.open("camp_equipment.txt");
	
	while (!input)
	{
		getline(input, oldInformation);
		output << oldInformation << endl;
	}
	
	input.close();
	output.close();
}

void admin::updateLoanStatus(string itemId, string status)
{
	ifstream input;
	ofstream output;
	string information, info;
	int position;
	input.clear();
	output.clear();
	input.open("loan_record.txt", ios::out);

	output.open("updating.txt");
	while (!input)
	{
		getline(input, information);

		position = information.find("|", 0);

		if (info.assign(information, position + 1, 4) == itemId)
		{
			if (status == "returned")
			{
				position = information.find("|out of loan", 0);
				information.assign(information, 0, position + 1);
				information.append("returned");
			}
			else
			{
				position = information.find("|returned", 0);
				information.assign(information, 0, position + 1);
				information.append("out of loan");
			}
		}
		output << information << endl;
	}
	input.close();
	output.close();
	input.open("tmp.txt");
	output.open("loan_record.txt");
	while (!input.eof())
	{
		getline(input, information);
		output << information << endl;
	}
	input.close();
	output.close();
}


void admin::makeLoan(User* user)
{
	FileHandler fH;
	string information, info, itemCode;
	Equipment* e = nullptr;
	ifstream input;
	ofstream output;
	while (true)
	{
		if (user->getStatus())
		{
			for (int i = 0; i < user->getLoanNumber(); )
			{
				cout << "Please input the equipment ID(input -1 to get back):";
				cin >> itemCode;
				e = fH.EquipmentIdentity(itemCode);
				if (itemCode == "-1")				
					break;
				
				if (user->getStatus() && e->returnStatus())
				{
					input.clear();
					input.open("camp_equipment.txt");
					while (!input)
					{
						getline(input, information);
						if (information.length() == 0)
						{

						}
						else
						{
							if (info.assign(information, 0, 4) == itemCode)
							{
								e = fH.EquipmentIdentity(info.assign(information, 0, 4));
								break;
							}
						}
					}
					user->borrowItem();
					input.close();
					updateEquipmentCondition(itemCode, "out");
					output.clear();
					output.open("loan_record.txt", ios::app);
					output << "2019/4/13|" << itemCode << "|" << e->returnitemName() << "|" << user->getUserName() << "|" << "2019/5/02" << "|" << "out of loan" << endl;
					i++;
					cout << "Loan has been made!" << endl;
				}
				else
				{
					cout << "That equipment is not available!" << endl;
				}
			}
			break;
		}
		else
		{
			cout << "Sorry, this option is not available!" << endl;
			break;
		}
	}
}

void admin::returnEquipments(User * user)
{
	string itemCode, infomation, info;
	int position1, position2;
	ifstream input;
	while (true)
	{
		if (!(user->getStatus()))	
		{
			cout << "You have nothing to return!" << endl;
			break;
		}
		cout << "Please input the Equipment ID(input -1 to get back):";
		cin >> itemCode;
		if (itemCode != "-1")
		{
			input.open("loan_record.txt");
			while (!input.eof())
			{
				getline(input, infomation);
				position1 = infomation.find("|", 0);
				position2 = infomation.find("|", position1 + 1);
				if (itemCode == info.assign(infomation, position1 + 1, position2 - position1 - 1))
				{
					position1 = infomation.find("|", position2 + 1);
					position2 = infomation.find("|", position1 + 1);
					if (user->getUserName() == info.assign(infomation, position1 + 1, position2 - position1 - 1))
					{
						user->returnItem();
						updateEquipmentCondition(itemCode, "in");
						updateLoanStatus(itemCode, "returned");
					}
					else
					{
						cout << "Please enter correct equipment ID!" << endl;
						break;
					}
				}
			}
		}
		else break;
	}
}
admin::admin() {
	_adminId = "admin";
	_adminPw = "admin";
}
admin::~admin() {}
	
bool admin::login(string adminId, string adminPw) {
	_adminId = adminId;
	_adminPw = adminPw;
	if (_adminId == "admin" && _adminPw == "admin") {
		cout << "1. Insert the text files" << endl;
		cout << "2. "
	}
	
}