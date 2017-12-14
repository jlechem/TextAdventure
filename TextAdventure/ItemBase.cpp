#include "stdafx.h"
#include "ItemBase.h"

ItemBase::ItemBase()
{
}

ItemBase::~ItemBase()
{
}

int ItemBase::getId()
{
	return _id;
}

void ItemBase::setId(int value)
{
	_id = value;
}

string ItemBase::getName()
{
	return _name;
}

void ItemBase::setName(string name)
{
	_name = name;
}

int ItemBase::getScore()
{
	return _scoreValue;
}

void ItemBase::setScore(int score)
{
	_scoreValue = score;
}

string ItemBase::getDescription()
{
	return _description;
}

void ItemBase::setDescription(string description)
{
	_description = description;
}
