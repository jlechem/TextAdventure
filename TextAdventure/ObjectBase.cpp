/*
	ObjectBase.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Map class.

*/


#include "stdafx.h"
#include "ObjectBase.h"


ObjectBase::ObjectBase()
{
	_name = "";
	_description = "";
	_id = 0;
	_score = 0;
	_type = ObjectType::ItemObject;
}

ObjectBase::ObjectBase(int id)
{
	_id = id;
}

ObjectBase::ObjectBase(string name, string description, int id, int score, ObjectType type)
{
	_name = name;
	_description = description;
	_id = id;
	_score = score;
	_type = type;
}

ObjectBase::~ObjectBase()
{
}

string ObjectBase::getName()
{
	return _name;
}

void ObjectBase::setName(string name)
{
	_name = name;
}

string ObjectBase::getDescription()
{
	return _description;
}

void ObjectBase::setDescription(string description)
{
	_description = description;
}

int ObjectBase::getId()
{
	return _id;
}

void ObjectBase::setId(int id)
{
	_id = id;
}

int ObjectBase::getScore()
{
	return _score;
}

void ObjectBase::setScore(int score)
{
	_score = score;
}

void ObjectBase::addToScore(int score)
{
	_score += score;
}

ObjectType ObjectBase::getType()
{
	return _type;
}

void ObjectBase::setType(ObjectType type)
{
	_type = type;
}