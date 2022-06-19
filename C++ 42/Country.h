#pragma once

class Country {
	string name = "";
	vector<City> cities;
	Location location;

	friend ostream& operator<<(ostream&, Country);

public:

	Country() = default;

	Country(string _name, vector<City>& _cities, Location& _location)
	{
		name = _name;
		cities = _cities;
		location = _location;
	}

	bool operator<(Country& c)
	{
		if (name < c.name)
			return true;
		return false;
	}


	bool operator>(Country& c)
	{
		if (name > c.name)
			return true;
		return false;
	}

};


ostream& operator<<(ostream& out, Country c)
{
	out << "Name : " << c.name << endl << "Location :\n\n" << "Latitude : " << c.location.latitude << "\nLongitude : "
		<< c.location.longitude << endl << "Cities : " << endl;

	for (size_t i = 0; i < c.cities.size(); i++)
		out << c.cities[i] << endl;
	out << endl;

	return out;
}
