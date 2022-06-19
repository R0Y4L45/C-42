#include <iostream>
#include <string>
#include <vector>


using namespace std;

#include "Location.h"
#include "City.h"
#include "Country.h"
#include "BST.h"
#include "World.h"


int main()
{
	Location loc("40.37 N", "49.95 E");
	Location loc1("39.37 N", "35.95 E");
	Location loc2("51.50 N", "0.12 E");
	Location loc3("50.37 N", "30.95 E");

	City c("Baku", loc, 3000000, true);
	City c1("Ankara", loc, 5000000, true);
	City c2("London", loc, 8000000, true);
	City c3("Kiyev", loc, 100, true);


	vector<City> cities = { c, c1, c2, c3 };


	Country country("Azerbaijan", cities, loc);
	Country country1("Turkey", cities, loc1);
	Country country2("England", cities, loc2);
	Country country3("Ukraine", cities, loc3);


	BST<Country> countries;
	countries.insert(country);
	countries.insert(country1);
	countries.insert(country2);
	countries.insert(country3);

	World world(countries);

	world.world.inOrder();

	world.world.deleteKey(country1);
	cout << endl;
	world.world.inOrder();




	return 0;
}