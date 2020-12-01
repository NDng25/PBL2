#include "Movie.h"

Movie::Movie(string id,string name,string dir,string cast,string date,string end_date,string des,string genre,int run,int price)
	:movie_id(id),name(name),dir(dir),cast(cast),release_date(date),end_show(end_date), des(des),genre(genre),running_time(run),price(price)
{

}

Movie::~Movie()
{

}


void Movie::showDetail()
{
  cout<<"Phim: "<<this->name<<endl
	  <<"Dao dien: "<<this->dir<<endl
	  <<"Dien vien: "<<this->cast<<endl
	  <<"The loai: "<<this->genre<<" Thoi luong: "<<this->running_time
	  <<"Ngay phat hanh: "<<this->release_date<<" Ngay dung chieu: "<<this->end_show<<endl
	  <<"Gia ve: "<<this->price<<endl;
}

void Movie::show()
{
  cout<<this->name<<" "<<"The loai: "<<this->genre<<endl;
}

Movie& Movie::operator=(const Movie& m)
{
	this->movie_id = m.movie_id;
	this->name = m.name;
	this->dir = m.dir;
	this->cast = m.cast;
	this->release_date = m.release_date;
	this->end_show = m.end_show;
	this->des = m.des;
	this->genre = m.genre;
	this->running_time = m.running_time;
	this->price = m.price;
	return *this;
}

string Movie::getid()
{
	return this->movie_id;
}

void Movie::setMovie(string id, string name, string dir, string cast, string date, string end, string des, string genre, int& run, int& price)
{
	this->movie_id = id;
	this->name = name;
	this->dir = dir;
	this->cast = cast;
	this->release_date = date;
	this->end_show = end;
	this->des = des;
	this->genre = genre;
	this->running_time = run;
	this->price = price;
}

void Movie::setName(string s)
{
	this->name = s;
}

string Movie::getName()
{
	return this->name;
}

void Movie::setDir(string s)
{
	this->dir = s;
}

string Movie::getDir()
{
	return this->dir;
}

void Movie::setCast(string s)
{
	this->cast = s;
}

string Movie::getCast()
{
	return this->cast;
}

void Movie::setRelease(string s)
{
	this->release_date = s;
}

string Movie::getRelease()
{
	return this->release_date;
}

void Movie::setEnd(string s)
{
	this->end_show = s;
}

string Movie::getEnd()
{
	return this->end_show;
}

void Movie::setDes(string s)
{
	this->des = s;
}

string Movie::getDes()
{
	return this->des;
}

void Movie::setGenre(string s)
{
	this->genre = s;
}

string Movie::getGenre()
{
	return this->genre;
}

void Movie::setRunning(const int& i)
{
	this->running_time = i;
}

const int Movie::getRunning()
{
	return this->running_time;
}

void Movie::setPrice(const int& i)
{
	this->price = i;
}

const int Movie::getPrice()
{
	return this->price;
}

ostream& operator<<(ostream& o, const Movie& m)
{
	o << "id: " << m.movie_id << endl
		<< "Ten phim: " << m.name << endl
		<< "Dao dien: " << m.dir << ", Dien vien chinh: " << m.cast << endl
		<< "Ngay phat hanh: " << m.release_date <<" Ngay dung chieu: "<<m.end_show<<endl 
		<<"Thoi luong: " << m.running_time<<" phut" << endl
		<< "Gia ve: " << m.price <<" VND"<< endl;
	return o;
}
