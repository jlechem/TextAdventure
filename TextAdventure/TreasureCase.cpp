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

void TreasureCase::addTreasure(unique_ptr<Treasure> treasure)
{
	_treasures.push_back(std::move(treasure));
	_score += treasure->getScore();
}

unique_ptr<Treasure> TreasureCase::removeTreasure(string)
{
	return unique_ptr<Treasure>();
}