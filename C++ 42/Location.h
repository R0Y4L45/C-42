#pragma once

struct Location {
	string longitude = "";
	string latitude = "";

	Location() = default;

	Location(string _longitude, string _latitude)
	{
		longitude = _longitude;
		latitude = _latitude;
	}
};


