#pragma once

#include "stdafx.h"
#include "Treasure.h"

class TreasureCase
{
public:
	TreasureCase();
	~TreasureCase();

	void setDescription(string);
	string getDescription();

	void addTreasure(unique_ptr<Treasure>);
	unique_ptr<Treasure> removeTreasure(string);

private:
	string _description;

	vector<unique_ptr<Treasure>> _treasures;
	int _score;

};