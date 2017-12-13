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
	generateItemString();
}

void Room::removeItem(string itemName)
{
	// TODO: remove item from vector
	generateItemString();
}

void Room::removeItem(unique_ptr<Item> item)
{
	// TODO: remove item from vector
	generateItemString();
}

void Room::addTreasure(unique_ptr<Treasure> treasure)
{
	_treasures.push_back(std::move(treasure));
	generateTreasureString();
}

void Room::removeTreasure(string treasureName)
{
	// TODO: remove treasure from vector
	generateTreasureString();
}

void Room::removeTreasure(unique_ptr<Treasure> treasure)
{
	// TODO: remove treasure from vector
	generateTreasureString();
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

void Room::generateItemString()
{
	std::vector<unique_ptr<Item>>::iterator it;

	_itemsString.clear();

	for (it = _items.begin(); it != _items.end(); ++it)
	{
		_itemsString += (*it)->getName();
		_itemsString += ",";
	}

	// take off the last comma
	_itemsString.erase(_itemsString.end() - 1);
}

void Room::generateTreasureString()
{
	std::vector<unique_ptr<Treasure>>::iterator it;

	_treasuresString.clear();

	for (it = _treasures.begin(); it != _treasures.end(); ++it)
	{
		_treasuresString += (*it)->getName();
		_treasuresString += ",";
	}

	// take off the last comma
	_treasuresString.erase(_treasuresString.end() - 1);

}

string Room::getItems()
{
	return _itemsString;
}

string Room::getTreasures()
{
	return _treasuresString;
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