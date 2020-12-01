#pragma once
#include "Movie.h"
class Movieshow
{
private:
	string showid;
	string movieid;
	string start;
	string end;
	Movie* movie;
public:
	Movieshow(string ="" , string ="" ,string ="" ,string = "",Movie* = nullptr);
	Movieshow(string, string, string, string);
	~Movieshow();
	

};

