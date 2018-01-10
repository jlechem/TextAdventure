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
	string result = _name + "\n\n" + _description;

	// add the exits
	map<Directions, Room*>::iterator it;

	string exits = "", items = "";

	for (it = _exits.begin(); it != _exits.end(); ++it)
	{
		exits += Utilities::convertDirection((*it).first);
		exits += ", ";
	}

	if (exits.size() > 2)
	{
		exits.erase(exits.end() - 2);
	}

	// add the item
	vector<unique_ptr<Item>>::iterator it2;

	for (it2 = _items.begin(); it2 != _items.end(); ++it2)
	{
		items += (*it2)->getName();

		if ((*it2)->getIsOpen())
		{
			items += " (open)";
		}

		items += ", ";
	}

	if (items.size() > 2)
	{
		items.erase(items.end() - 2);
	}

	if (exits.size() > 0)
	{
		result += "\nYou see the following exits: " + exits;
	}

	if (items.size() > 0)
	{
		result += "\nYou see the following items: " + items;
	}

	return result;

}

map<Directions, Room*>& Room::getExits()
{
	return _exits;
}

void Room::setExits(map<Directions, Room*>& exits)
{
	_exits = exits;
}

void Room::addExit(Directions exit, Room* room)
{
	_exits[exit] = room;
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

	return result;

}

vector<unique_ptr<Item>>* Room::getAllItems()
{
	return &_items;
}

void Room::increaseVisitCount()
{
	_visitCount++;
}

unsigned long Room::getVisitCount()
{
	return _visitCount;
}

void Room::updateVisitCount()
{
	_visitCount++;
}