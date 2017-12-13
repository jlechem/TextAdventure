#include "stdafx.h"
#include "Room.h"

Room::Room()
{
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

int Room::getId()
{
	return _id;
}

void Room::setId(int id)
{
	_id = id;
}

string Room::getName()
{
	return _name;
}

void Room::setName(string name)
{
	_name = name;
}

string Room::getDescription()
{
	return _description;
}

void Room::setDescription(string description)
{
	_description = description;
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
}

void Room::removeItem(string itemName)
{
}

void Room::removeItem(unique_ptr<Item> item)
{
}

void Room::addTreasure(unique_ptr<Treasure> treasure)
{
	_treasures.push_back(std::move(treasure));
}

void Room::removeTreasure(string treasureName)
{
}

void Room::removeTreasure(unique_ptr<Treasure> treasure)
{
}

string Room::getExits()
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

void Room::generateExitString()
{
	std::map<Directions, shared_ptr<Room>>::iterator it;

	_exitString.clear();

	for (it = _exits.begin(); it != _exits.end(); ++it)
	{
		_exitString += convertDirectionToString(it->first);
		_exitString += ",";
	}

	// take off the last comma
	_exitString.erase(_exitString.end() - 1);

}

string Room::convertDirectionToString(Directions direction)
{
	string result;

	switch (direction)
	{
	case North:
		result = "North";
		break;

	case South:
		result = "South";
		break;

	case East:
		result = "East";
		break;
	
	case West:
		result = "West";
		break;
	
	case NorthWest:
		result = "North West";
		break;
	
	case NorthEast:
		result = "North East";
		break;
	
	case SouthEast:
		result = "South East";
		break;
	
	case SouthWest:
		result = "South West";
		break;

	}

	return result;

}