#include "Admin.h"
#include "user.h"
#include "camp_equipment.h"
#include "loanControl.h"
#include "filehandler.h"
#include <iostream>
using namespace std;

void Admin::displayloanRecord() {
	string line;
	ifstream file;
	file.open("user.txt");
	string user;

	if (file.is_open()) {
		while (getline(file, user))
			cout << user << endl;
	}
	cout << endl;
	file.close;
}
void Admin::loanRecord(int loanDate, string itemCode, string itemName,
	string NameOfBorrower, int returnDate, string status) {
	this->_loanDate = loanDate;
	this->_itemCode = itemCode;
	this->_itemName = itemName;
	this->_NameOfBorrower = NameOfBorrower;
	this->_returnDate = returnDate;
	this->_status = status;
}

void Admin::produceNewTextFile() {
	ifstream file;
	ifstream user("loanRecord.txt");
	ifstream campEquipment("EquipementList.txt");
	ofstream combined_file("loan.txt");
	combined_file << user.rdbuf() << campEquipment.rdbuf();

	file.close();
}
