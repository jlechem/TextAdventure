/*
	TreasureCase.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents the treasure chest in the game
*/

#pragma once

#include "stdafx.h"
#include "Item.h"

class TreasureCase
{
public:
	TreasureCase();
	~TreasureCase();

	void setDescription(string);
	string getDescription();

	void addTreasure(unique_ptr<Item>);
	unique_ptr<Item> removeTreasure(string);

private:
	string _description;

	vector<unique_ptr<Item>> _items;

	int _score;

};