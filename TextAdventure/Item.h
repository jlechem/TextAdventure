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

class Item
{
public:
	Item();
	~Item();

	int getId();
	void setId(int);

	string getName();
	void setName(string);

	int getScore();
	void setScore(int);

	string getDescription();
	void setDescription(string);

	ItemType getType();
	void setType(ItemType);

	void addAlternateName(string);
	vector<string>& getAlterateNames();

private:
	int _id;
	string _name;
	string _description;
	int _score;
	vector<string> _alternateNames;

	ItemType _type;

	vector<Item> _subItems;

};