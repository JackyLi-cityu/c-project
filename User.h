#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {								//	It is ABC (Abstract Class)
protected:									//	Convenient for inheritane in this class User
	//	Set the identity of user (general)
	string _UserId;
	string _UserName;
	string _Section;
	int _birthday;
	string _Address;
	string _password;						//	prepare for login
	int _UpperLoanLimit;					//	for updating the number of quota
	bool borrowing = false;					//	Assume the user did not borrow before
public:
	string getUserId();
	string getUserName();
	string getSection();
	int getDateOfBirth();
	string getAddress();
	void setUserId(string UserId);
	void setPassword(string password);
	void setLoanStatus(bool status);
	void setLoanNumber(int number);
	int getLoanNumber();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
	User();
	~User();
	User(string UserId, string UserName, string Section, int DateOfBirth, string Address);
};


class Scout : public User {
protected:
	string _Rank;
public:
	Scout(string Id, string Name, string Section, int DateOfBirth, string Address, string  _Rank);
	Scout();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
};


class VentureScout : public User {
public:
	VentureScout(string UserId, string UserName, string Section, int DateOfBirth, string Address);
	VentureScout();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
};


class RoverScout : public User {
public:
	RoverScout(string UserId, string UserName, string Section, int DateOfBirth, string Address);
	RoverScout();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
};


class Scouter : public User {
private:
	string _Rank;
public:
	Scouter(string UserId, string Name, string Section, int DateOfBirth, string Address, string Rank);
	Scouter();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
};
#endif 
