#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>
#include <string>
#include "camp_equipment.h"
#include "User.h"

class FileHandler
{
public:
	Equipment *EquipmentIdentity(string UserId);
	User *UserIdentity(string itemCode);
	void displayEquipmentList();
	bool login(string UserId, string DateOfBirth);
	void changeLoanStatus(User* user);
};

#endif 
