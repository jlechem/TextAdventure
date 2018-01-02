/*
	Armor.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: A class that reprsents a armor

*/

#pragma once

#include "stdafx.h"

#include "ObjectBase.h""
#include "Room.h"
#include "Item.h"

class Armor
	: public ObjectBase
{
public:
	Armor();
	Armor(int);
	Armor(string, string, int, int, ObjectType);
	~Armor();

	int getDefenseRating();
	void setDefenseRating(int);

private:
	int _defenseRating;

};