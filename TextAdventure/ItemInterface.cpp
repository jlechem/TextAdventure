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

string ItemInterface::openItem(string name)
{
	// empty means success
	string result = "";

	// first check if we even have this fucking thing
	auto item = findItem(name);

	if (item)
	{
		// can we open this thing?
		if (item->getCanOpen())
		{
			// is it already open
			if (item->getIsOpen())
			{
				result = ": Already open";
			}
			else
			{
				item->setIsOpen(true);
			}
		}
		else
		{
			result = ": Nice try";
		}
	}
	else
	{
		result = ": Not found";
	}

	return result;

}

string ItemInterface::closeItem(string name)
{
	// empty means success
	string result = "";

	// first check if we even have this fucking thing
	auto item = findItem(name);

	if (item)
	{
		// can we open this thing?
		if (item->getCanOpen())
		{
			// is it already closed
			if (!item->getIsOpen())
			{
				result = ": Already closed";
			}
			else
			{
				item->setIsOpen(false);
			}
		}
		else
		{
			result = ": Nice try";
		}
	}
	else
	{
		result = ": Not found";
	}

	return result;
}