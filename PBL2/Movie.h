 #pragma once
#include <string>
#include <iostream>
using namespace std;
class Movie
{
private:
	string movie_id;
	string name;
	string dir;
	string cast;
	string release_date;
	string end_show;
	string des;
	string genre;
	int running_time;
	int price;
public:
	Movie(string = "",string = "",string ="",string = "",string ="",string ="",string ="",string ="",int = 0,int = 0);
	~Movie();
	void showDetail();
	void show();
	Movie& operator=(const Movie&); 
	friend ostream& operator<<(ostream&, const Movie&);
	string getid();
	void setMovie(string, string, string, string, string, string, string, string, int&, int&);
	void setName(string);
	string getName();
	void setDir(string);
	string getDir();
	void setCast(string);
	string getCast();
	void setRelease(string);
	string getRelease();
	void setEnd(string);
	string getEnd();
	void setDes(string);
	string getDes();
	void setGenre(string);
	string getGenre();
	void setRunning(const int&);
	const int getRunning();
	void setPrice(const int&);
	const int getPrice();
};

