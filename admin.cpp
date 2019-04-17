#include "admin.h"
using namespace std;

void admin::displayLoanRecord(string userName)
{
	ifstream input;
	string information, info;
	int position1, position2, NumofReturned;
	NumofReturned = 0;			// initialize before use
	input.clear();
	input.open("loan_record.txt");
	while (!input.eof())
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
	{
		cout << "No loan is made yet." << endl;
	}
}

void admin::updateEquipmentCondition(string eID, string status)
{
	ifstream input;
	ofstream output;
	input.clear();
	output.clear();
	string reg, _reg, r;
	input.open("camp_equipment.txt");
	output.open("updating.txt");
	
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.length() == 0)
		{

		}
		else
		{
			if (r.assign(reg, 0, 3) == eID)
			{
				
				if (status == "out")
				{
					int pos = reg.find("|in|", 0);
					_reg = reg.assign(reg, pos + 3, reg.length() - pos - 4);
					reg = reg.assign(reg, 0, pos);
					reg = reg.append("out");
					reg = reg.append(_reg);
				}
				else
				{
					int pos = reg.find("|out|", 0);
					_reg = reg.assign(reg, pos + 3, reg.length() - pos - 4);
					reg = reg.assign(reg, 0, pos);
					reg = reg.append("in");
					reg = reg.append(_reg);
				}
			}
			output << reg << endl;
		}
	}
	input.close();
	output.close();
	input.open("tmp.txt", ios::beg);
	output.open("camp_equipment.txt");
	
	while (!input.eof())
	{
		getline(input, reg);
		output << reg << endl;
	}
	
	input.close();
	output.close();
}

void admin::updateLoanStatus(string eID, string status)
{
	ifstream input;
	ofstream output;
	string reg, r;
	int pos;
	input.clear();
	output.clear();
	input.open("loan_record.txt", ios::out);
	output.open("tmp.txt");
	while (!input.eof())
	{
		getline(input, reg);
		pos = reg.find("|", 0);
		if (r.assign(reg, pos + 1, 4) == eID)
		{
			if (status == "returned")
			{
				pos = reg.find("|out of loan", 0);
				reg.assign(reg, 0, pos + 1);
				reg.append("returned");
			}
			else
			{
				pos = reg.find("|returned", 0);
				reg.assign(reg, 0, pos + 1);
				reg.append("out of loan");
			}
		}
		output << reg << endl;
	}
	input.close();
	output.close();
	input.open("tmp.txt");
	output.open("loan_record.txt");
	while (!input.eof())
	{
		getline(input, reg);
		output << reg << endl;
	}
	input.close();
	output.close();
}


void admin::makeLoan(User* user)
{
	FileHandler fH;
	string reg, eID, r;
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
				cin >> eID;
				e = fH.EquipmentIdentity(eID);
				if (eID == "-1")				
					break;
				
				if (user->getStatus() && e->returnStatus())
				{
					input.clear();
					input.open("camp_equipment.txt");
					while (!input.eof())
					{
						getline(input, reg);
						if (reg.length() == 0)
						{

						}
						else
						{
							if (r.assign(reg, 0, 4) == eID)
							{
								e = fH.EquipmentIdentity(r.assign(reg, 0, 4));
								break;
							}
						}
					}
					user->borrowItem();
					input.close();
					updateEquipmentCondition(eID, "out");
					output.clear();
					output.open("loan_record.txt", ios::app);
					output << "2019/4/13|" << eID << "|" << e->returnitemName() << "|" << user->getUserName() << "|" << "2019/5/02" << "|" << "out of loan" << endl;
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
	string eID, reg, r;
	int pos1, pos2;
	ifstream input;
	while (true)
	{
		if (user->getStatus())
		{

		}
		else
		{
			cout << "You have nothing to return!" << endl;
			break;
		}
		cout << "Please input the Equipment ID(input -1 to get back):";
		cin >> eID;
		if (eID != "-1")
		{
			input.open("loan_record.txt");
			while (!input.eof())
			{
				getline(input, reg);
				pos1 = reg.find("|", 0);
				pos2 = reg.find("|", pos1 + 1);
				if (eID == r.assign(reg, pos1 + 1, pos2 - pos1 - 1))
				{
					pos1 = reg.find("|", pos2 + 1);
					pos2 = reg.find("|", pos1 + 1);
					if (user->getUserName() == r.assign(reg, pos1 + 1, pos2 - pos1 - 1))
					{
						user->returnItem();
						updateEquipmentCondition(eID, "in");
						updateLoanStatus(eID, "returned");
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