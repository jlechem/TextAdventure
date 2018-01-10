/*
	ActorBase.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		01-02-2018
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the ActorBase class.

*/

#include "stdafx.h"

#include "ActorBase.h"

ActorBase::ActorBase()
{
	_level = 0;
	_score = 0;
	_numberOfMoves = 0;
	_description = "";
	_name = "";
	_id = 0;
}

ActorBase::ActorBase(Room* initialRoom)
{
	_level = 0;
	_score = 0;
	_numberOfMoves = 0;
	_description = "";
	_name = "";
	_id = 0;
	_currentRoom = initialRoom;
}

ActorBase::~ActorBase()
{
	delete _currentRoom;
}

unsigned int ActorBase::getId()
{
	return _id;
}

void ActorBase::setId(unsigned int id)
{
	_id = id;
}

unsigned int ActorBase::getScore()
{
	return _score;
}

void ActorBase::setScore(unsigned int score)
{
	_score = score;
}

void ActorBase::addToScore(unsigned int score)
{
	_score += score;
}

string ActorBase::getName()
{
	return _name;
}

void ActorBase::setName(string name)
{
	_name = name;
}

string ActorBase::getDescription()
{
	return _description;
}

void ActorBase::setDescription(string description)
{
	_description = description;
}

vector<unique_ptr<Item>>* ActorBase::getInventory()
{
	return &_items;
}

bool ActorBase::addItem(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));

	return true;
}

bool ActorBase::addItem(string name)
{
	bool result = false;

	// check if our room has an item or teasure with this name
	auto item = _currentRoom->findItem(name);

	if (item != nullptr && item->getCanTake() )
	{
		_score += item->getScore();
		_items.push_back(std::move(item));
		result = true;
	}

	return result;

}

unique_ptr<Item> ActorBase::dropItem(string name, bool x = false)
{
	return nullptr;
}

bool ActorBase::dropItem(string name)
{
	bool result = false;

	// find the item in our collection if it exists
	auto foundItem = findItem(name);

	if (foundItem != nullptr)
	{
		_score -= foundItem->getScore();
		_currentRoom->addItem(std::move(foundItem));
		result = true;
	}

	return result;

}

Room* ActorBase::getCurrentRoom()
{
	return _currentRoom;
}

void ActorBase::setCurrentRoom(Room* room)
{
	_currentRoom = room;
}

bool ActorBase::Move(string direction)
{
	bool result = false;

	// first get the enum from the string
	Directions enumDirection = Utilities::convertDirection(direction);

	if (enumDirection != Directions::Invalid )
	{
		// get the shared pointer from the map we have
		auto newRoom = getCurrentRoom()->getExits()[enumDirection];

		if (newRoom != nullptr)
		{
			_numberOfMoves++;
			_currentRoom = newRoom;
			_currentRoom->updateVisitCount();
			result = true;
		}
	}

	return result;

}

unsigned long ActorBase::getMoveCount()
{
	return _numberOfMoves;
}

void ActorBase::attack(shared_ptr<ActorBase> defender)
{
	// TODO: implement attack
}

void ActorBase::defend(shared_ptr<ActorBase> attacker)
{
	// TODO: implement defend
}

unsigned int ActorBase::getHitPoints()
{
	return _hitpoints;
}

void ActorBase::setHitPoints(unsigned int hp)
{
	_hitpoints = hp;
}

unsigned int ActorBase::getLevel()
{
	return _level;
}

void ActorBase::setLevel(unsigned int level)
{
	_level = level;
}

void ActorBase::levelUp()
{
	_level++;
}

unique_ptr<Item> ActorBase::findItem(string name)
{
	unique_ptr<Item> result = nullptr;

	vector<unique_ptr<Item>>::iterator it;

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