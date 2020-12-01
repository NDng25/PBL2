#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	string acc_id;
	string staff_id;
	string username;
	string password;
public:
	Account(string ="",string ="",string ="",string = "");
	~Account();
	string getId();
	string getUsername();
	string getPass();
	const Account& operator=(const Account&);
};

