#pragma once
#include "Search.h"
using namespace std;

Search::Search(string inputYear)
{
	for (auto itr = searchMovies.movieList.begin(); itr != searchMovies.movieList.end(); ++itr)
	{
		if (itr->year == inputYear)
		{
			searchmovieList.push_back(*itr);
		}
	}
}