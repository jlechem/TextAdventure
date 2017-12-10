#include "stdafx.h"
#include "Room.h"

Room::Room()
{
	_exits = make_unique<map<Directions, shared_ptr<Room>>>();
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

string Room::getShortDescription()
{
	return _shortDesctiption;
}

void Room::setShortDescription(string shortDescription)
{
	_shortDesctiption = shortDescription;
}

unique_ptr<map<Directions, shared_ptr<Room>>> Room::getExits()
{
	return std::move(_exits);
}

void Room::setExits(unique_ptr<map<Directions, shared_ptr<Room>>> exits)
{
	_exits = std::move(exits);
}

void Room::addExit(Directions exit, shared_ptr<Room> room)
{
	(*_exits)[exit] = room;
}