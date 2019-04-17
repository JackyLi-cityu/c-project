#ifndef ADMIN_H 
#define ADMIN_H
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "LoanControl.h"
#include "FileHandler.h"
class admin
{
private:
	string _adminId;
	string _adminPw;

public:
	void displayLoanRecord(string UserId);
	void updateEquipmentCondition(string itemId, string status);
	void updateLoanStatus(string itemId, string status);
	void makeLoan(User* user);
	void returnEquipments(User* user);
	
};

#endif // !ADMIN_H 