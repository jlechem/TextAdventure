#include "stdafx.h"
#include "Player.h"
#include "Item.h"

Player::Player()
{
}

Player::Player(shared_ptr<Room> initialRoom)
{
	_currentRoom = initialRoom;
}

Player::~Player()
{
}

vector<unique_ptr<Item>>* Player::getInventory()
{
	return &_items;
}

bool Player::addItem(string name)
{
	bool result = false;

	// check if our room has an item or teasure with this name
	unique_ptr<Item> item = _currentRoom->findItem(name);

	if (item != nullptr)
	{
		_items.push_back(std::move(item));
		result = true;
	}
	
	return result;

}

unique_ptr<Item> Player::dropItem(string name)
{
	return findItem(name);
}

shared_ptr<Room> Player::getCurrentRoom()
{
	return _currentRoom;
}

bool Player::Move(string direction)
{
	bool result = false;

	// first get the enum from the string
	auto enumDirection = convertDirection(direction);

	// get the shared pointer from the map we have
	auto newRoom = getCurrentRoom()->getExits()[enumDirection];

	if (newRoom != nullptr)
	{
		_currentRoom = newRoom;
		result = true;
	}

	return result;

}

int Player::getScore()
{
	return _score;
}

Directions Player::convertDirection(string direction)
{
	Directions result = Directions::Invalid;
	
	if (direction == "n" || direction == "north")
	{
		result = Directions::North;
	}
	else if (direction == "s" || direction == "south")
	{
		result = Directions::South;
	}
	else if (direction == "e" || direction == "east")
	{
		result = Directions::East;
	}
	else if (direction == "w" || direction == "west")
	{
		result = Directions::West;
	}
	else if (direction == "ne" || direction == "northeast" || direction == "north east")
	{
		result = Directions::NorthEast;
	}
	else if (direction == "se" || direction == "southeast" || direction == "south east")
	{
		result = Directions::SouthEast;
	}
	else if (direction == "sw" || direction == "southwest" || direction == "south west")
	{
		result = Directions::SouthWest;
	}
	else if (direction == "nw" || direction == "northwest" || direction == "north west")
	{
		result = Directions::NorthWest;
	}
	
	return result;
}

unique_ptr<Item> Player::findItem(string name)
{
	unique_ptr<Item> temp = nullptr;

	vector<unique_ptr<Item>>::iterator it;

	for (auto i = 0; i < _items.size(); i++) 
	{
		if ( _items[i]->getName() == name )
		{
			temp = std::move(_items[i]);
		}
	}

	return std::move(temp);
}

void Player::printInventory()
{
	vector<unique_ptr<Item>>::iterator it;

	cout << "You have the following items" << endl;

	for (it = _items.begin(); it != _items.end(); ++it)
	{
		cout << (*it)->getName() << endl;
	}
}