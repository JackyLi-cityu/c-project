#ifndef CAMPEQUIPMENT_H
#define CAMPEQUIPMENT_H
#include <iostream>
#include <string>
using namespace std;

class Equipment			//	the Equipment class is also the ABC, the following diplayInfo will be used in the menu
{
private:
	//	basic info for identifying different camp equipments
	string _itemCode;		
	string _itemName;		
	string _brand;		
	string _EquipType;		
	int _PurchaseDate;			
	string _condition;	
	string _status;		
public:
	Equipment(string itemCode, string itemName, string brand, string EquipType,
		int Purchasedate, string condition, string status);
	~Equipment();
	void displayCommonInfo();						// Display basic information
	virtual void displayAttributeInfo();	//	Display attribute
	bool returnStatus();
	string returnitemName();
};

class tent : public Equipment
{
private:
	int _tentSize;		
	string _tentType;	
	int _numberOfDoors;	
	bool _doubleLayer;	
	string _colour;		
public:
	virtual void displayAttributeInfo();	//	display the unique features of tent
};

class stove : public Equipment
{
private:
	string _stoveType;
	string _fuelType;
public:
	virtual void displayAttributeInfo();
};

class lantern : public Equipment
{
private:
	string _lanternSize;	
	string _lanternType;	
	string _fuelType;	
public:
	virtual void displayAttributeInfo();	
};


#endif 