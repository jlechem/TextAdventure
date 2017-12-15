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

private:
	int _id;
	string _name;
	string _description;
	int _scoreValue;
	
	ItemType _type;

	vector<Item> _subItems;

};