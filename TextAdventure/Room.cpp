#include "stdafx.h"
#include "Room.h"

Room::Room()
{
}

Room::~Room()
{
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

vector<Directions> Room::getExits()
{
	return _exits;
}

void Room::setExits(vector<Directions> exits)
{
	_exits = exits;
}

void Room::addExit(Directions exit)
{
	_exits.push_back(exit);
}

void Room::removeExit(Directions exit)
{
	// TODO: find item in vector and remove it
}