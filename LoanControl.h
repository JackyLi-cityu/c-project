#ifndef LOANCONTROL_H
#define LOANCONTROL_H
#include <iostream>
#include <string>
#include "User.h"
#include "camp_equipment.h"
#include "FileHandler.h"
using namespace std;

class loanControl
{
public:
	bool check(User* user, Equipment* equip) {
		if (user->getStatus() && equip->returnStatus())
			return true;
		else return false;
	}
};
#endif 
