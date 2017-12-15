#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	_type = ItemType::BaseItem;
}

Item::~Item()
{
}

int Item::getId()
{
	return _id;
}

void Item::setId(int value)
{
	_id = value;
}

string Item::getName()
{
	return _name;
}

void Item::setName(string name)
{
	_name = name;
}

int Item::getScore()
{
	return _scoreValue;
}

void Item::setScore(int score)
{
	_scoreValue = score;
}

string Item::getDescription()
{
	return _description;
}

void Item::setDescription(string description)
{
	_description = description;
}

ItemType Item::getType()
{
	return _type;
}

void Item::setType(ItemType type)
{
	_type = type;
}