/*
	File:						ItemsInterface.h
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-9-2018

	Notes:					Implementation of the ItemInterface class

*/

#include "stdafx.h"

#include "ItemInterface.h"

ItemInterface::ItemInterface()
{
}

ItemInterface::~ItemInterface()
{
}

vector<unique_ptr<Item>>& ItemInterface::getItems()
{
	return _items;
}

void ItemInterface::addItem(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));
}

bool ItemInterface::addItem(string name)
{
	bool result = false;

	auto item = findItem(name);
	
	if (item)
	{
		_items.push_back(std::move(item));
		result = true;
	}
	
	return result;

}

unique_ptr<Item> ItemInterface::dropItem(string name)
{
	return std::move(findItem(name));
}

unique_ptr<Item> ItemInterface::findItem(string name)
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