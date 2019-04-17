#include "camp_equipment.h"
using namespace std;

Equipment::Equipment(string itemCode, string itemName, string brand, string EquipType, int PurchaseDate, string condition, string status)
{
	_itemCode = itemCode;
	_itemName = itemName;
	_brand = brand;
	_EquipType = EquipType;
	_PurchaseDate = PurchaseDate;
	_condition = condition;
	_status = status;
}

Equipment::~Equipment(){}

void Equipment::displayCommonInfo()
{
	cout << _itemCode << "|" << _itemName << "|" << _brand << "|" << _EquipType << "|" << _PurchaseDate << "|" << _condition << "|" << _status << endl;
}

void Equipment::displayAttributeInfo(){}


bool Equipment::returnStatus()
{
	if (_status == "in")
		return true;
	else return false;
}

string Equipment::returnitemName()
{
	return _itemName;
}

//	make use of this pure virtual function in different types of camp equipments

void tent::displayAttributeInfo()
{
	cout << "|" << _tentSize << "|" << _tentType << "|" << _numberOfDoors << "|" << _doubleLayer << "|" << _colour << endl;
}

void stove::displayAttributeInfo()
{
	cout << "|" << _stoveType << "|" << _fuelType << endl;
}

void lantern::displayAttributeInfo()
{
	cout << "|" << _lanternSize << "|" << _lanternType << "|" << _fuelType << endl;
}

