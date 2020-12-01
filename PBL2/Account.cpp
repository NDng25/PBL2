#include "Account.h"

Account::Account(string id, string sid, string uname, string pass)
	:acc_id(id),staff_id(sid),username(uname),password(pass)
{
}

Account::~Account()
{
}

string Account::getId()
{
	return this->acc_id;
}

string Account::getUsername()
{
	return this->username;
}

string Account::getPass()
{
	return this->password;
}

const Account& Account::operator=(const Account& a)
{
	this->acc_id = a.acc_id;
	this->staff_id = a.staff_id;
	this->username = a.username;
	this->password = a.password;
	return *this;
}

