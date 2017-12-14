#include "stdafx.h"
#include "Player.h"

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

void Player::addItem(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));
}

unique_ptr<Item> Player::dropItem(string name)
{
	return findItem(name);
}

vector<unique_ptr<Treasure>>* Player::getTreasures()
{
	return &_treasures;
}

void Player::addTreasure(unique_ptr<Treasure> treasure)
{
	_treasures.push_back(std::move(treasure));
}

unique_ptr<Treasure> Player::dropTreasure(string name)
{
	return findTreasure(name);
}

shared_ptr<Room> Player::getCurrentRoom()
{
	return _currentRoom;
}

bool Player::Move(Directions direction)
{
	bool result = false;

	// get the value from our map for this key
	auto newRoom = _currentRoom->getExits()[direction];

	if (newRoom)
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

unique_ptr<Treasure> Player::findTreasure(string name)
{
	unique_ptr<Treasure> temp = NULL;

	vector<unique_ptr<Treasure>>::iterator it;

	for (it = _treasures.begin(); it != _treasures.end(); ++it)
	{
		if ( (*it)->getName() == name)
		{
			temp = std::move((*it));
			_treasures.erase(it);
		}
	}

	return temp;
	
}