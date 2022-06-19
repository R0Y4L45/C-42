#pragma once


class City {
	string name = "";
	Location location;
	size_t population = 0;
	bool isCapital = true;

	friend ostream& operator<<(ostream& out, City& c);

public:

	City() = default;

	City(string _name, Location _location, size_t _population, bool _isCapital)
	{
		name = _name;
		location = _location;
		population = _population;
		isCapital = _isCapital;
	}
	
};


ostream& operator<<(ostream& out, City& c)
{
	out << "Name : " << c.name << endl << "Location :\n\n" << "Latitude : " << c.location.latitude << "\nLongitude : "
		<< c.location.longitude << "Is it Capital ?  -> " << boolalpha << c.isCapital << endl
		<< "Population : " << c.population << endl;
	return out;
}