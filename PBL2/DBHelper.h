#pragma once
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Movie.h"
//#include "Staff.h"
#include "Account.h"
#include<iomanip>
#include<conio.h>
//#include <string.h>
// #include<string.h>
#include <string>
using namespace std;
class DBHelper
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLTCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void init();
	void Insert(const char*);
//	void InsertMovie(const string);
	int SelectCount(string);
	vector<Movie> SelectMovie();
	Movie SelectMovie(string);
	vector<Account> SelectAccount(string,string);
	void Update();
	void Delete(const char*);
	void ShowError(unsigned int, const SQLHANDLE&);
//	void ListMovie();
	void close();
};

