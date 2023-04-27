#include "Movie.h"
#include <iostream>

Movie::Movie() {
	title = "";
	year = "";
	rating = "";
	popularity = "";
	revenue = "";
}

Movie::Movie(string title, string year, string rating, string popularity, string revenue){
	this->title = title;
	this->year = year;
	this->rating = rating;
	this->popularity = popularity;
	this->revenue = revenue;
}

string Movie::Print() {

	return title + " (" + year + ") " + "\n" + "Rating: " + rating + "  |  Popularity: " + popularity + "\n\n";
}