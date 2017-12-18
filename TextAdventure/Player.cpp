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
	unique_ptr<Item> item = std::move(_currentRoom->findItem(name));

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
	return false;

	bool result = false;

}

int Player::getScore()
{
	return _score;
}

Directions Player::convertDirection(string direction)
{
	return Directions();
}

shared_ptr<Room> Player::getNextRoom(Directions direction)
{
	shared_ptr<Room> room();

	return shared_ptr<Room>();
}

unique_ptr<Item> Player::findItem(string name)
{
	unique_ptr<Item> temp = NULL;

	vector<unique_ptr<Item>>::iterator it;

	for (auto i = 0; i < _items.size(); i++) 
	{
		if ( _items[i]->getName() == name )
		{
			temp = std::move(_items[i]);
		}
	}

	return temp;
}