#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>
using namespace std;

class Movie {
public:
	// Constructor
	Movie();
	Movie(string title, string year, string rating, string popularity, string revenue);

	string Print();

	string title;
	string year;
	string rating;
	string popularity;
	string revenue;
};
#endif