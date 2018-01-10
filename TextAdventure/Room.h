/*
	File:						Room.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	1-9-2018

	Notes:					A class that represents a room in the game

	*/

#pragma once

#include "stdafx.h"

#include "Item.h"
#include "ItemInterface.h"
#include "ObjectBase.h"
#include "Utils.h"

class Room 
	: public ObjectBase, public ItemInterface
{
public:
	Room();
	Room(int, string, string, string);
	~Room();

	string getShortDescription();
	void setShortDescription(string);
	string getLongDescription();

	void addItem(unique_ptr<Item>);
	
	unique_ptr<Item>& Room::getItem(string);

	string getExitsString();
	map<Directions, Room*>& getExits();
	void setExits(map<Directions, Room*>&);
	void addExit(Directions, Room*);
	
	string findItemDescription(string name);

	unique_ptr<Item> findItem(string);
	
	vector<unique_ptr<Item>>* getAllItems();

	string getItemsString();
	void setItemsString(string);

	unsigned long getVisitCount();
	void updateVisitCount();

	
private:
	unsigned long _visitCount;

	string _shortDesctiption;
	string _exitString;
	string _itemsString;

	vector<unique_ptr<Item>> _items;
	map<Directions,Room*> _exits;
	
	void generateExitString();
	void generateItemString();
	void increaseVisitCount();

};