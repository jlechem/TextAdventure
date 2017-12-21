/*
	ActorBase.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the ActorBase class.

*/

#include "stdafx.h"
#include "ActorBase.h"

ActorBase::ActorBase()
{
	_score = 0;
	_numberOfMoves = 0;
	_description = "";
	_name = "";
	_id = 0;
}

ActorBase::ActorBase(shared_ptr<Room> initialRoom)
{
	_score = 0;
	_numberOfMoves = 0;
	_description = "";
	_name = "";
	_id = 0;
	_currentRoom = initialRoom;
}

ActorBase::~ActorBase()
{
}

int ActorBase::getId()
{
	return _id;
}

void ActorBase::setId(int id)
{
	_id = id;
}

int ActorBase::getScore()
{
	return _score;
}

void ActorBase::setScore(int score)
{
	_score = score;
}

void ActorBase::addToScore(int score)
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

bool ActorBase::addItem(string name)
{
	bool result = false;

	// check if our room has an item or teasure with this name
	unique_ptr<Item> item = _currentRoom->findItem(name);

	if (item != nullptr)
	{
		_score += item->getScore();
		_items.push_back(std::move(item));
		result = true;
	}

	return result;

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

shared_ptr<Room> ActorBase::getCurrentRoom()
{
	return _currentRoom;
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

int ActorBase::getHitPoints()
{
	return _hitpoints;
}

void ActorBase::setHitPoints(int hp)
{
	_hitpoints = hp;
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
			break;
		}
	}

	return std::move(result);
}
