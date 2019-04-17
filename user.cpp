#include<iostream>
#include "User.h"
#include "FileHandler.h"
using namespace std;


string User::getUserId() {
	return _UserId;
}

string User::getUserName() {
	return _UserName;
}

string User::getSection() {
	return _Section;
}

int User::getDateOfBirth() {
	return _DateOfBirth;
}

string User::getAddress() {
	return _Address;
}

void User::setUserId(string id)
{
	this->_UserId = id;
}

void User::setPassword(string password)
{
	this->_password = password;
}

void User::setLoanStatus(bool status)
{
	borrowing = status;
}

void User::setLoanNumber(int number)
{
	_UpperLoanLimit -= number;
}

int User::getLoanNumber()
{
	return _UpperLoanLimit;
}

bool User::getStatus()
{
	if (_UpperLoanLimit == 0)
		return false;
	else return true;
}


void User::borrowItem() {}
void User::returnItem() {}

User::User() {}
User::~User() {}

User::User(string UserId, string UserName, string Section, int DateOfBirth, string Address) {
	_UserId = UserId;
	_UserName = UserName;
	_Section = Section;
	_DateOfBirth = DateOfBirth;
	_Address = Address;
}

Scout::Scout(string UserId, string UserName, string Section, int DateOfBirth, string Address, string  Rank) {
	this->_UserId = UserId;
	this->_UserName = UserName;
	this->_Section = Section;
	this->_DateOfBirth = DateOfBirth;
	this->_Address = Address;
	_Rank = Rank;
	_UpperLoanLimit = Rank == "Assistant Patrol Leader" || Rank == "Patrol Leader" ? 3 : 1;
}

Scout::Scout() {}

bool Scout::getStatus()
{
	if (_UpperLoanLimit == 0)	
		return false;
	else return true;
	
}

void Scout::borrowItem()
{
	_UpperLoanLimit--;
	borrowing = true;
}

void Scout::returnItem()
{
	_UpperLoanLimit++;
	borrowing = _UpperLoanLimit == 3 && (_Rank == "Assistant Patrol Leader" || _Rank == "Patrol Leader")  ? false : true;
	borrowing = _UpperLoanLimit == 1 && _Rank == "Member" ? false : true;
}

VentureScout::VentureScout(string UserId, string UserName, string Section, int DateOfBirth, string Address) {
	this->_UserId = UserId;
	this->_UserName = UserName;
	this->_Section = Section;
	this->_DateOfBirth = DateOfBirth;
	this->_Address = Address;
	_UpperLoanLimit = 3;
}

VentureScout::VentureScout() {}

bool VentureScout::getStatus()
{
	if (_UpperLoanLimit == 0)
		return false;
	else return true;
}

void VentureScout::borrowItem()
{
	_UpperLoanLimit--;
	borrowing = true;
}

void VentureScout::returnItem()
{
	_UpperLoanLimit++;
	if (_UpperLoanLimit == 3)
		borrowing = false;
}

RoverScout::RoverScout(string UserId, string UserName, string Section, int DateOfBirth, string Address) {
	this->_UserId = UserId;
	this->_UserName = UserName;
	this->_Section = Section;
	this->_DateOfBirth = DateOfBirth;
	this->_Address = Address;
	_UpperLoanLimit = 5;
}

RoverScout::RoverScout() {}


bool RoverScout::getStatus()
{
	if (_UpperLoanLimit == 0)
		return false;	
	else return true;
}

void RoverScout::borrowItem()
{
	_UpperLoanLimit--;
	borrowing = true;
}

void RoverScout::returnItem()
{
	_UpperLoanLimit++;
	if (_UpperLoanLimit == 5)
		borrowing = false;
}

Scouter::Scouter(string UserId, string UserName, string Section, int DateOfBirth, string Address, string Rank) {
	this->_UserId = UserId;
	this->_UserName = UserName;
	this->_Section = Section;
	this->_DateOfBirth = DateOfBirth;
	this->_Address = Address;
	_Rank = Rank;
	_UpperLoanLimit = 5;
}

Scouter::Scouter() {}

bool Scouter::getStatus()
{
	if (_UpperLoanLimit == 0)
		return false;
	else return true;
}

void Scouter::borrowItem()
{
	_UpperLoanLimit--;
	borrowing = true;
}

void Scouter::returnItem()
{
	_UpperLoanLimit++;
	if (_UpperLoanLimit == 5)
		borrowing = false;
}
