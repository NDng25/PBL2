#include "Customer.h"

Customer::Customer(string id, string ten, string diachi, int sdt, string email, string pw)
{
	this->CustomerId = id;
	this->ten = ten;
	this->diachi = diachi;
	this->sdt = sdt;
	this->email = email;
	this->Password = pw;
}

Customer::Customer()
{
	this->CustomerId = "";
	this->ten = "";
	this->diachi = "";
	this->sdt = 0;
	this->email = "";
	this->Password = "";
}

Customer::~Customer()
{

}

void Customer::setname(string name)
{
	this->ten = name;
}

string Customer::getname()
{
	return this->ten;
}

void Customer::setid(string id)
{
	this->CustomerId = id;
}

string Customer::getid()
{
	return this->CustomerId;
}

void Customer::setpw(string pw)
{
	this->Password = pw;
}

string Customer::getpw()
{
	return this->Password;
}
