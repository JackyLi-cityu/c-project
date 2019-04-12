#include "filehandler.h"		//	insert tabulated files
#include "camp_equipment.h"		// display list of camp equipment
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Admin
{
private:
	string _UserId;
	string _password;
	int _loanDate;
	string _itemCode;
	string _itemName;
	string _NameOfBorrower;
	int _returnDate;
	string _status;

public:
	Admin();
	void loanRecord(int _loanDate, string _itemCode, string _itemName,
		string _NameOfBorrower, int _returnDate, string _status); // point no.2
	void displayloanRecord();
	void produceNewTextFile();
};
#endif 
