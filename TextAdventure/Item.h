/*
	Item.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
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
	~Item();

	ItemType getItemType();
	void setItemType(ItemType);

	void addAlternateName(string);
	vector<string>& getAlterateNames();

private:
	int _id;
	int _score;

	string _name;
	string _description;
	
	vector<string> _alternateNames;

	ItemType _itemType;

	vector<Item> _subItems;

};