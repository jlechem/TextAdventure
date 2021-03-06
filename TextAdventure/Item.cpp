/*
	Item.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		1-11-2018
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Item class.

*/

#include "stdafx.h"
#include "Item.h"

Item::Item(): 
	ObjectBase()
{
	_isOpen = false;
	_canOpen = false;
	_canTake = true;
	_itemType = ItemType::BaseItem;
	_type = ObjectType::ItemObject;
}

Item::Item(string name, string description, int id, int score, ObjectType type)
{
	_name = name;
	_description = description;
	_id = id;
	_score = score;
	_type = type;
	_isOpen = false;
	_canOpen = false;
	_canTake = true;
	_itemType = ItemType::BaseItem;
}

Item::Item(int id)
{
	_id = id;
	_isOpen = false;
	_canOpen = false;
	_canTake = true;
	_itemType = ItemType::BaseItem;
	_type = ObjectType::ItemObject;
}

/*
	Inits a new instance of the Item class. We're assuming if you give something a capacity it can be opened. I guess you could set
	this to zero and false to be a fucking dick. So go ahead and you be you.
*/
Item::Item(int capacity, int, bool canOpen = true, bool canTake = false)
	:ObjectBase()
{
	_canTake = canTake;
	_canOpen = canOpen;
	_subItemCapacity = capacity;

	_subItems.resize(_subItemCapacity);
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

bool Item::getCanOpen()
{
	return _canOpen;
}

void Item::setCanOpen(bool canOpen)
{
	_canOpen = canOpen;
}

bool Item::getIsOpen()
{
	return _isOpen;
}

void Item::setIsOpen(bool isOpen)
{
	_isOpen = isOpen;
}

bool Item::getCanAddItem()
{
	return _canAddItems;
}

void Item::setCanAddItem(bool canAdd)
{
	_canAddItems = canAdd;
}

int Item::getSubItemCapacity()
{
	return _subItemCapacity;
}

void Item::setSubItemCapacity(int capacity)
{
	_subItemCapacity = capacity;
}

int Item::getSubItemCount()
{
	return _subItems.size();
}

vector<unique_ptr<Item>>& Item::getItems()
{
	return _subItems;
}

bool Item::addItem(unique_ptr<Item> item)
{
	bool result = false;

	// if this item isn't full and we can add stuff to it
	if (_canAddItems &&
		_subItems.size() < _subItemCapacity)
	{
		_subItems.push_back(std::move(item));
		result = true;
	}

	return result;

}

bool Item::removeItem(string name)
{
	return false;
}

bool Item::getCanTake()
{
	return _canTake;
}

void Item::setCanTake(bool canTake)
{
	_canTake = canTake;
}

bool Item::getIsFull()
{
	return _subItems.size() <= _subItemCapacity;
}

ItemSizes Item::getItemSize() 
{
	return _itemSize;
}