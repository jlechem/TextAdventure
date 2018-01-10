/*
	File:						ItemInterface.h
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-9-2018

	Notes:					A class that represents a collection of items, a player, room, or NPC can all have items

*/

#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Room.h"

class ItemInterface
{
public:
	ItemInterface();
	~ItemInterface();
	
	vector<unique_ptr<Item>>& getItems();
	void addItem(unique_ptr<Item>);
	unique_ptr<Item> findItem(string);
	
protected:
	vector<unique_ptr<Item>> _items;

};