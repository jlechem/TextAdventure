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
	_visitCount = 0;
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

string Room::getLongDescription()
{
	string result = _description;

	if (_exitString.size() > 0)
	{
		result += "\nYou see the following exits: " + _exitString;
	}

	if (_itemsString.size() > 0)
	{
		result += "\nYou see the following items: " + _itemsString;
	}

	return result;

}

void Room::addItem(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));
	generateItemString();
}

map<Directions, Room*>& Room::getExits()
{
	return _exits;
}

string Room::getExitsString()
{
	return _exitString;
}

void Room::setExits(map<Directions, Room*>& exits)
{
	_exits = exits;
	generateExitString();
}

void Room::addExit(Directions exit, Room* room)
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

unique_ptr<Item>& Room::getItem(string name)
{
	vector<unique_ptr<Item>>::iterator it;

	unique_ptr<Item> result = nullptr;

	// loop through all the items in this room and search for the one we want
	for (it = _items.begin(); it != _items.end(); ++it)
	{
		auto temp = find((*it)->getAlterateNames().begin(), (*it)->getAlterateNames().end(), name);

		if (temp != (*it)->getAlterateNames().end())
		{
			return (*it);
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

	return result;

}

vector<unique_ptr<Item>>* Room::getAllItems()
{
	return &_items;
}

void Room::generateItemString()
{
	_itemsString.clear();

	vector<unique_ptr<Item>>::iterator it;

	for ( it = _items.begin(); it != _items.end(); ++it )
	{
		_itemsString += (*it)->getName();
		_itemsString += ", ";
	}

	if (_itemsString.size() > 2)
	{
		// take off the last comma and space
		_itemsString.erase(_itemsString.end() - 2);
	}
}

void Room::increaseVisitCount()
{
	_visitCount++;
}

string Room::getItemsString()
{
	return _itemsString;
}

void Room::setItemsString(string itemsString)
{
	_itemsString = itemsString;
}

unsigned long Room::getVisitCount()
{
	return _visitCount;
}

void Room::updateVisitCount()
{
	_visitCount++;
}

void Room::generateExitString()
{
	std::map<Directions, Room*>::iterator it;

	_exitString.clear();

	for (it = _exits.begin(); it != _exits.end(); ++it)
	{
		_exitString += Utilities::convertDirection(it->first);
		_exitString += ", ";
	}

	// take off the last comma
	if (_exitString.size() >= 2)
	{
		_exitString.erase(_exitString.end() - 2);
	}
}