#include "Movieshow.h"



Movieshow::Movieshow(string showid, string movieid, string start, string end)
	:showid(showid), movieid(movieid), start(start), end(end)
{
	this->movie = nullptr;
}

Movieshow::~Movieshow()
{
	delete[] this->movie;
}
