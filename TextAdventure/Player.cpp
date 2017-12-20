/*
Map.cpp
Created By:			Justin LeCheminant
Created On:			12-20-2017
Last Modified:		12-20-2017
Last Modified By:	Justin LeCheminant

Notes: Implementation of the Player class.

*/

#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	_type = ObjectType::PlayerObject;
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

bool Player::dropItem(string name)
{
	bool result = false;

	// find the item in our collection if it exists
	auto foundItem = findItem(name);

	if (foundItem != nullptr)
	{
		_currentRoom->addItem(std::move(foundItem));
		result = true;
	}

	return result;

}

shared_ptr<Room> Player::getCurrentRoom()
{
	return _currentRoom;
}

bool Player::Move(string direction)
{
	bool result = false;

	// first get the enum from the string
	Directions enumDirection = Utilities::convertDirection(direction);

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

unique_ptr<Item> Player::findItem(string name)
{
	unique_ptr<Item> result = nullptr;

	vector<unique_ptr<Item>>::iterator it;

	for (it = _items.begin(); it != _items.end(); ++it)
	{
		auto temp = find((*it)->getAlterateNames().begin(), (*it)->getAlterateNames().end(), name);

		if (temp != (*it)->getAlterateNames().end())
		{
			result = std::move((*it));
			break;
		}
	}

	return std::move(result);
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