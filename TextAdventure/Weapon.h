/*
	Weapon.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: A class that reprsents a weapon

*/

#pragma once

#include "stdafx.h"

#include "ObjectBase.h"
#include "Armor.h"
#include "Room.h"
#include "Item.h"

class Weapon
	: public ObjectBase
{
public:
	Weapon();
	Weapon(int);
	Weapon(string, string, int, int, ObjectType);
	~Weapon();

	double getDamage();
	void setDamage(double);

	double getSpeed();
	void setSpeed(double);


private:
	double _damage;
	double _speed;


};