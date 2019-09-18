/*
	File:			Item.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	1-26-2018

	Notes:			A class that represents an item in the game

*/

#pragma once

#include "stdafx.h"

#include "ItemType.h"
#include "ObjectBase.h"

class Item: public ObjectBase
{
public:
	Item();
	Item(int);
	Item(int, int, bool,bool);
	Item(string, string, int, int, ObjectType);
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

	int getSubItemCount();

	vector<unique_ptr<Item>>& getItems();

	bool addItem(unique_ptr<Item>);
	bool removeItem(string);

	bool getCanTake();
	void setCanTake(bool);

	bool getIsFull();

protected:
	bool _canOpen;
	bool _isOpen;
	bool _canAddItems;
	bool _canTake;

private:	
	int _subItemCapacity;

	vector<string> _alternateNames;

	ItemType _itemType;

	vector<unique_ptr<Item>> _subItems;

};