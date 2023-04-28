#include <fstream>
#include <sstream>
#include "Database.h"
using namespace std;

Database::Database()
{
	ifstream inputFile("movies_metadata.csv");

	string line = "";
	getline(inputFile, line);
	int count = 0;

	// Reads and parsees input from metadata
	while (getline(inputFile, line))
	{
		Movie movieObject;
		stringstream ss(line);
		while (getline(ss, line, ','))
		{
			if (count % 24 == 7)
				movieObject.language = line;
			if (count % 24 == 8)
				movieObject.title = line;
			if (count % 24 == 14)
				movieObject.year = (line.substr(line.find("/") + 1)).substr((line.substr(line.find("/") + 1)).find("/") + 1);
			if (count % 24 == 10)
				movieObject.popularity = line;
			if (count % 24 == 22)
				movieObject.rating = line;
			if (count % 24 == 15)
				movieObject.revenue = line;
			count++;
		}
		movieList.push_back(movieObject);
	}
	inputFile.close();
}