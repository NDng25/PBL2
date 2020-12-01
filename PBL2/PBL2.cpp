#include "Management.h"
#include "Admin.h"
#include "Account.h"

int main()
{
	Admin a;
//	a.Login();
	a.DisplayMovieList();
	//a.AddMovie();
	//a.DeleteMovie();
	//a.UpdateMovie();
	vector<Account> acc;
	Account tmp("", "", "", "");
	acc.push_back(tmp);

	system("PAUSE");
}