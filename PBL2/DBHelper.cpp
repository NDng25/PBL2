#include "DBHelper.h"

void themdau(string s)
{
	string s1 = "'";
	s = (s1 + s + s1);
}

void DBHelper::init()
{
	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();

	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";
	switch (SQLDriverConnect(sqlConnHandle, NULL,(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=NINH_DUONG\\SQLEXPRESS;DATABASE=bookTicket;trusted = true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		ShowError(SQL_HANDLE_DBC, sqlConnHandle);
		cout << "\n";
		close();
		break;

	default:
		break;
	}
	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}

//void DBHelper::Select(Movie& m, const int& id) 
//{
//	
//	//output
//	cout << "\n";
//	cout << "Executing T-SQL query...";
//	cout << "\n";
//    string s = "SELECT * FROM movie WHERE movie_id = ";
//	string s1 = to_string(id);
//	string s2;
//	s2 = s + s1;
//	cout << s2;
//	const char* n = s2.c_str();
//	/*for (int i = 0; i < 50; i++)
//	{
//		n[i] = s2[i];
//	}*/
//	//if there is a problem executing the query then exit application
//	//else display query resultS
//	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)n, SQL_NTS)) {
//		ShowError(SQL_HANDLE_DBC, sqlStmtHandle);
//		cout << "Error querying SQL Server";
//		cout << "\n";
//		close();
//	}
//	else {
//		//declare output variable and pointer
//		SQLINTEGER ptrSqlVersion;
//		char m_id[5];
//		char name[30];
//		char dir[30];
//		char cast[30];
//		char release_date[20];
//		char end_show[20];
//		char des[100];
//		char genre[50];
//		int running_time;
//		int price;
//		if (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
//			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, m_id, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, name, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, dir, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, cast, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, release_date, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, end_show, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, des, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, genre, SQL_RESULT_LEN, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 9, SQL_INTEGER, &running_time, 1, &ptrSqlVersion);
//			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &price, 1, &ptrSqlVersion);
//			
//	/*		string sname(name);
//			string sdir(dir);
//			string scast(cast);
//			string sdate(release_date);
//			string sdes(des);
//			string sgenre(genre);*/
// 			Movie tmp(string(m_id), string(name), string(dir), string(cast), string(release_date),string(end_show) , string(des), string(genre), running_time, price);
//			m = tmp;
//		}
//	}
//	SQLCancel(sqlStmtHandle);
//}

int DBHelper::SelectCount(string s)
{
	int count;
	cout << "\n";
	cout << "Executing T-SQL query... movie";
	cout << "\n";
	const char* str = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS)) {
		ShowError(SQL_HANDLE_DBC, sqlStmtHandle);
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char m_id[5];
		char name[30];
		char dir[30];
		char cast[30];
		char release_date[20];
		char end[30];
		char des[100];
		char genre[50];
		int running_time;
		int price;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &count, 1, &ptrSqlVersion);
		}
		return count;
	}
	SQLCancel(sqlStmtHandle);
}

vector<Movie> DBHelper::SelectMovie()
{
	vector<Movie> movie;
	cout << "\n";
	cout << "Executing T-SQL query... movie";
	cout << "\n";
	//const char* n = s2.c_str();
	/*for (int i = 0; i < 50; i++)
	{
		n[i] = s2[i];
	}*/
	//if there is a problem executing the query then exit application
	//else display query resultS
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM movie", SQL_NTS)) {
		ShowError(SQL_HANDLE_DBC, sqlStmtHandle);
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char m_id[5];
		char name[30];
		char dir[30];
		char cast[30];
		char release_date[20];
		char end[30];
		char des[100];
		char genre[50];
		int running_time;
		int price;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, m_id, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, dir, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, cast, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, release_date, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, end, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, des, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, genre, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_INTEGER, &running_time, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &price, 1, &ptrSqlVersion);
			Movie* tmp = new Movie(string(m_id), string(name), string(dir), string(cast), string(release_date),string(end), string(des), string(genre), running_time, price);
			movie.push_back(*tmp);
			delete tmp;
		}
		return movie;
	}
	SQLCancel(sqlStmtHandle);
}

Movie DBHelper::SelectMovie(string s)
{
	//Movie tmp;
	cout << "\n";
	cout << "Executing T-SQL query... movie";
	cout << "\n";
	string s1 = "SELECT * FROM movie WHERE movie_id = '";
	string s2 = "'";
	string s3 = s1 + s + s2;
	const char* str = s3.c_str();
	//const char* n = s2.c_str();
	/*for (int i = 0; i < 50; i++)
	{
		n[i] = s2[i];
	}*/
	//if there is a problem executing the query then exit application
	//else display query resultS
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS)) {
		ShowError(SQL_HANDLE_DBC, sqlStmtHandle);
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char m_id[5];
		char name[30];
		char dir[30];
		char cast[30];
		char release_date[20];
		char end[30];
		char des[100];
		char genre[50];
		int running_time;
		int price;
		if (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, m_id, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, dir, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, cast, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, release_date, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, end, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, des, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, genre, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_INTEGER, &running_time, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &price, 1, &ptrSqlVersion);
			//tmp.setMovie(string(m_id), string(name), string(dir), string(cast), string(release_date), string(end), string(des), string(genre), running_time, price);
		}
		return Movie(string(m_id), string(name), string(dir), string(cast), string(release_date), string(end), string(des), string(genre), running_time, price);
	}
	SQLCancel(sqlStmtHandle);
}

vector<Account> DBHelper::SelectAccount(string us, string ps)
{
	vector<Account> acc;
	cout << "\n";
	cout << "Executing T-SQL query... movie";
	cout << "\n";
	string s1 = "SELECT * FROM account WHERE username = '";
	string s2 = "' AND password = '";
	string s3 = s1 + us + s2 + ps +"'" ;
	const char* str = s3.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS)) {
		ShowError(SQL_HANDLE_DBC, sqlStmtHandle);
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char acc_id[5];
		char staff_id[5];
		char username[100];
		char pass[100];
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, acc_id, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, staff_id, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, username, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, pass, SQL_RESULT_LEN, &ptrSqlVersion);
			Account *tmp =  new Account(string(acc_id),string(staff_id),string(username),string(pass));
			acc.push_back(*tmp);
			delete tmp;
		}
	}
	return acc;
	SQLCancel(sqlStmtHandle);
}

void DBHelper::Insert(const char* str)
{
	cout << str << endl;
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS)) {
		cout << "\n";
		cout << SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS) << endl;
		cout << SQL_SUCCESS << endl;
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		cout << "\nINSERT SUCCESS\n";
		return;
	}
}

void DBHelper::Update()
{
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"UPDATE Student SET Id = 'hs1' where Id = 'hs1'", SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nUPDATE SUCCESS";
		return;
	}
}

void DBHelper::Delete(const char* str)
{
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)str, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
}

void DBHelper::close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
//	system("pause");
//	exit(0);
}

void DBHelper::ShowError(unsigned int HandleType, const SQLHANDLE& handle)
{
	SQLWCHAR SQLState[1024];
	SQLWCHAR Message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(HandleType, handle, 1, SQLState,NULL, Message, 1024,NULL))
	{
		cout << "SQL Driver Message: " << Message << "\nSQL State: " << SQLState << "." << endl;
	}
}

//SQLCHAR							SalesPerson[11];
//SQLINTEGER				SalesPersonLenOrInd, CustIDInd;
//SQLUINTEGER			CustID;
////	Bind	SalesPerson	to	the	parameter	for	the	SalesPerson	column	and
////	CustID	to	the	parameter	for	the	CustID	column.
//SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 10, 0, SalesPerson, sizeof(SalesPerson), &SalesPersonLenOrInd);
//SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 10, 0, 	&CustID, 0, &CustIDInd);
////	Set	values	of	salesperson	and	customer	ID	and	length/indicators.
//strcpy_s((char*)SalesPerson, _countof(SalesPerson), "Garcia");
//SalesPersonLenOrInd = SQL_NTS;
//CustID = 1331;
//CustIDInd = 0;
////	Execute	a	statement	to	get	data	for	all	orders	made	to	the	specified
////	customer	by	the	specified	salesperson.
//SQLExecDirect(hstmt1, "SELECT	*	FROM	Orders	WHERE	SalesPerson=?	AND	CustID=?", SQL_NTS);
////	Prepare	the	procedure	invocation	statement.
//SQLPrepare(hstmt, "{call	test(?)}", SQL_NTS);
////	Populate	record	1	of	ipd.
//SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
//	30, 0, szQuote, 0, &cbValue);
////	Get	ipd	handle	and	set	the	SQL_DESC_NAMED	and	SQL_DESC_UNNAMED	fields
////	for	record	#1.
//SQLGetStmtAttr(hstmt, SQL_ATTR_IMP_PARAM_DESC, &hIpd, 0, 0);
//SQLSetDescField(hIpd, 1, SQL_DESC_NAME, "@quote", SQL_NTS);
////	Assuming	that	szQuote	has	been	appropriately	initialized,
////	execute.
//SQLExecute(hstmt);
