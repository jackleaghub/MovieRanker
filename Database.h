#pragma once
#include <string>
#include <vector>
#include "Movie.h"
using namespace std;

struct Database
{
	vector<Movie> movieList;
	Database();
};