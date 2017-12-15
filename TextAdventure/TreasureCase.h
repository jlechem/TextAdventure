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