#pragma once
#include <string>
#include "Database.h"
using namespace std;

struct Search
{
	Database searchMovies;
	vector<Movie> searchmovieList;
	Search(string inputYear);
};