#include "Management.h"

Management::Management()
{
//	this->c = nullptr;
//	this->m = nullptr;
//	this->p = nullptr;
}

Management::~Management()
{
//	delete[] this->c;
//	delete[] this->m;
	//delete[] this->p;
}

void Management::MovieList()
{
	cout << "Danh sach cac phim dang chieu: " << endl;
	/*
		select database 
	*/
	//db.ListMovie();
}

Movie Management::SelectMovie( DBHelper& db, const int& id)
{
	Movie m;
	int ch;
	cout << "Nhap id phim: ";
	cin>> ch;
//	db.Select(m, ch);
	//cout << m << endl;
	return m;
}
