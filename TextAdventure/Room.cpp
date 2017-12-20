/*
	Room.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Room class.

*/

#include "stdafx.h"
#include "Room.h"


Room::Room(): ObjectBase()
{
	_type = ObjectType::RoomObject;
}

Room::~Room()
{
}

Room::Room(int id, string name, string description, string shortDescription ): Room()
{
	_id = id;
	_name = name;
	_description = description;
	_shortDesctiption = shortDescription;
}

string Room::getShortDescription()
{
	return _shortDesctiption;
}

void Room::setShortDescription(string shortDescription)
{
	_shortDesctiption = shortDescription;
}

void Room::addItem(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));
	generateItemString();
}

void Room::removeItem(string itemName)
{
	generateItemString();
}

void Room::removeItem(unique_ptr<Item> item)
{
	generateItemString();
}

map<Directions, shared_ptr<Room>>& Room::getExits()
{
	return _exits;
}

string Room::getExitsString()
{
	return _exitString;
}

void Room::setExits(map<Directions, shared_ptr<Room>>& exits)
{
	_exits = exits;
	generateExitString();
}

void Room::addExit(Directions exit, shared_ptr<Room> room)
{
	_exits[exit] = room;
	generateExitString();
}

string Room::findItemDescription(string name)
{
	vector<unique_ptr<Item>>::iterator it;

	string result = "";

	// loop through all the items in this room and search for the one we want
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		auto temp = find((*it)->getAlterateNames().begin(), (*it)->getAlterateNames().end(), name);

		if (temp != (*it)->getAlterateNames().end())
		{
			result = (*it)->getDescription();
			break;
		}
	}

	return result;

}

unique_ptr<Item> Room::findItem(string name)
{
	vector<unique_ptr<Item>>::iterator it;

	unique_ptr<Item> result = nullptr;

	// loop through all the items in this room and search for the one we want
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		auto temp = find((*it)->getAlterateNames().begin(), (*it)->getAlterateNames().end(), name);

		if (temp != (*it)->getAlterateNames().end())
		{
			result = std::move((*it));
			_items.erase(it);
			break;
		}
	}

	generateItemString();

	return std::move(result);

}

void Room::generateItemString()
{
	_itemsString.clear();

	for (auto i = 0; i < _items.size(); i++)
	{
		_itemsString += _items[i]->getName();
		_itemsString += ", ";
	}

	if (_itemsString.size() > 2)
	{
		// take off the last comma and space
		_itemsString.erase(_itemsString.end() - 2);
	}
}

string Room::getItemsString()
{
	return _itemsString;
}

void Room::generateExitString()
{
	std::map<Directions, shared_ptr<Room>>::iterator it;

	_exitString.clear();

	for (it = _exits.begin(); it != _exits.end(); ++it)
	{
		_exitString += Utilities::convertDirection(it->first);
		_exitString += ",";
	}

	// take off the last comma
	_exitString.erase(_exitString.end() - 1);

}