#pragma once


class World
{
public:


	BST<Country> world;

	friend ostream& operator<<(ostream&, World);


	World(BST<Country> _world)
	{
		world = _world;
	}
};


