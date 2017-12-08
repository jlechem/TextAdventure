#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	_items = new vector<unique_ptr<Item>>();
	_treasures = new vector<unique_ptr<Treasure>>();
}

Player::~Player()
{
	delete _items;
	delete _treasures;
}

vector<unique_ptr<Item>>* Player::getInventory()
{
	return _items;
}

void Player::addItem(unique_ptr<Item> item)
{
	_items->push_back(std::move(item));
}

unique_ptr<Item> Player::dropItem(string name)
{
	return findItem(name);
}

vector<unique_ptr<Treasure>>* Player::getTreasures()
{
	return _treasures;
}

void Player::addTreasure(unique_ptr<Treasure> treasure)
{
	_treasures->push_back(std::move(treasure));
}

unique_ptr<Treasure> Player::dropTreasure(string name)
{
	return findTreasure(name);
}

unique_ptr<Item> Player::findItem(string name)
{
	unique_ptr<Item> temp = NULL;

	vector<unique_ptr<Item>>::iterator it;

	for (auto i = 0; i < _items->size(); i++) 
	{
		if ( _items->operator[](i)->getName() == name )
		{
			temp = std::move(_items->operator[](i));
		}
	}

	return temp;
}

unique_ptr<Treasure> Player::findTreasure(string name)
{
	unique_ptr<Treasure> temp = NULL;

	vector<unique_ptr<Treasure>>::iterator it;

	for (auto i = 0; i < _treasures->size(); i++)
	{
		if (_treasures->operator[](i)->getName() == name)
		{
			temp = std::move(_treasures->operator[](i));
		}
	}

	return temp;


}
