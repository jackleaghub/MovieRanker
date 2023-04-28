#pragma once
#include "Search.h"
using namespace std;

// Pushes movie object into vector if it has correct release year and is english
Search::Search(string inputYear)
{
	for (auto itr = searchMovies.movieList.begin(); itr != searchMovies.movieList.end(); ++itr)
	{
		if (itr->year == inputYear && itr->language == "en")
		{
			searchmovieList.push_back(*itr);
		}
	}
}