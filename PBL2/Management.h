#pragma once
#include "Movie.h"
#include "Customer.h"
#include "Admin.h"
#include "Person.h"
#include "DBHelper.h"
using namespace std;
class Management
{
private:
//	Person* p;
//	Customer* c;
//	Admin* c;
//	Movie* m;
//	DBHelper *db;
public:
	Management();
	~Management();
	void MovieList();
	Movie SelectMovie(DBHelper &,const int&);
};

