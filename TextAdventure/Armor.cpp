/*
	Weapon.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: Implementation of the armor class.

*/

#pragma once

#include "stdafx.h"

#include "Armor.h"

Armor::Armor()
	: ObjectBase()
{
	_type = ObjectType::ArmorObject;
}

Armor::Armor(int id)
	: ObjectBase( id)
{
	_type = ObjectType::ArmorObject;
}

Armor::Armor(string name, string description, int id, int score, ObjectType type)
	: ObjectBase(name, description, id, score, type)
{
}

Armor::~Armor()
{
}

int Armor::getDefenseRating()
{
	return _defenseRating;
}

void Armor::setDefenseRating(int rating)
{
	_defenseRating = rating;
}