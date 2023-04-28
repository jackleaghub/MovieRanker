#include "Movie.h"
#include <iostream>

Movie::Movie() {
	title = "";
	year = "";
	rating = "";
	popularity = "";
	revenue = "";
	language = "";
}

Movie::Movie(string title, string year, string rating, string popularity, string revenue,string language){
	this->title = title;
	this->year = year;
	this->rating = rating;
	this->popularity = popularity;
	this->revenue = revenue;
	this->language = language;
}

// Returns in format to be outputted on form
string Movie::Print() {
	return title + " (" + year + ") " + "\n" + "Rating: " + rating + "  |  Popularity: " + popularity + "\n\n";
}