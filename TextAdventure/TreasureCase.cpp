/*
	TreasureCase.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the TreasureCase class.

*/

#include "stdafx.h"
#include "TreasureCase.h"

TreasureCase::TreasureCase()
{
	_score = 0;
}

TreasureCase::~TreasureCase()
{
}

void TreasureCase::setDescription(string description)
{
	_description = description;
}

string TreasureCase::getDescription()
{
	return _description;
}

void TreasureCase::addTreasure(unique_ptr<Item> item)
{
	_items.push_back(std::move(item));
	_score += item->getScore();
}

unique_ptr<Item> TreasureCase::removeTreasure(string)
{
	return unique_ptr<Item>();
}