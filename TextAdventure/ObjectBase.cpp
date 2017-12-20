#include "stdafx.h"
#include "ObjectBase.h"


ObjectBase::ObjectBase()
{
}

ObjectBase::ObjectBase(string name, string description, int score, ObjectType type)
{
	_name = name;
	_description = description;
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