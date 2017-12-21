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

Player::Player(): ActorBase()
{
}

Player::Player(shared_ptr<Room> initialRoom): ActorBase(initialRoom)
{

}

Player::~Player()
{
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

string Player::takeAllItems()
{
	string result = "";
	
	vector<unique_ptr<Item>>::iterator it;

	// get all the items from this room
	vector<unique_ptr<Item>>* items = _currentRoom->getAllItems();

	if (items->size() == 0)
	{
		result = "There's nothing here to take";
	}
	else
	{
		result = "You take the following items: ";

		// loop through the items in the room and add them to our inventory
		// add them to the players inventory
		for (it = items->begin(); it != items->end(); ++it)
		{
			result += (*it)->getName() + ", ";
			_items.push_back(std::move((*it)));
		}

		items->clear();

		_currentRoom->setItemsString("");

		// clear any ', ' at the end
		if (result.size() > 2)
		{
			result.erase(result.end() - 2, result.end());
		}
	}
	
	return result;

}

string Player::dropAllItems()
{
	string result = "";

	vector<unique_ptr<Item>>::iterator it;

	if (_items.size() == 0)
	{
		result = "You don't have anything";
	}
	else
	{
		result = "You drop the following items: ";

		// loop through the items in the room and add them to our inventory
		// add them to the players inventory
		for (it = _items.begin(); it != _items.end(); ++it)
		{
			result += (*it)->getName() + ", ";
		
			_currentRoom->addItem(std::move((*it)));
			
		}

		_items.clear();

		// clear any ', ' at the end
		if (result.size() > 2)
		{
			result.erase(result.end() - 2, result.end());
		}
	}

	return result;

}