/*
	Item.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-24-2017

	Notes: A class that represents an item in the game

*/

#pragma once

#include "stdafx.h"

#include "ItemType.h"
#include "ObjectBase.h"

class Item: public ObjectBase
{
public:
	Item();
	Item(int, int, bool,bool);
	~Item();

	ItemType getItemType();
	void setItemType(ItemType);

	void addAlternateName(string);
	vector<string>& getAlterateNames();

	bool getCanOpen();
	void setCanOpen(bool);

	bool getIsOpen();
	void setIsOpen(bool);

	bool getCanAddItem();
	void setCanAddItem(bool);

	int getSubItemCapacity();
	void setSubItemCapacity(int);

	bool addItem(unique_ptr<Item>);
	bool removeItem(string);

	bool getCanTake();
	void setCanTake(bool);

private:	
	bool _canOpen;
	bool _isOpen;
	bool _canAddItems;
	bool _canTake;

	int _subItemCapacity;

	vector<string> _alternateNames;

	ItemType _itemType;

	vector<Item> _subItems;

};