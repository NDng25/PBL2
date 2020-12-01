#pragma once
#include "DBHelper.h"
#include "Movie.h"
//#include "Staff.h"
#include "Account.h"
#include <vector>
#include <iostream>
using namespace std;


class Admin
{
private:
public:
	Admin();
	~Admin();
	void Login();
	void DisplayMovieList();
	void AddMovie();
	void DeleteMovie();
	void UpdateMovie();
};

