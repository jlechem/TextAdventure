/*
	Item.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Item class.

*/

#include "stdafx.h"
#include "Item.h"

Item::Item(): 
	ObjectBase()
{
	_itemType = ItemType::BaseItem;
	_type = ObjectType::ItemObject;
}

Item::~Item()
{
}

ItemType Item::getItemType()
{
	return _itemType;
}

void Item::setItemType(ItemType type)
{
	_itemType = type;
}

void Item::addAlternateName(string name)
{
	_alternateNames.push_back(name);
}

vector<string>& Item::getAlterateNames()
{
	return _alternateNames;
}