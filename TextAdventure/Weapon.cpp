/*
	Weapon.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: Implementation of the weapon class.

*/

#include "stdafx.h"

#include "Weapon.h"

Weapon::Weapon()
{
	_damage = _speed = 0.0;
	_type = ObjectType::WeaponObject;
}

Weapon::Weapon(int id)
	:ObjectBase(id)
{
	_damage = _speed = 0.0;
	_type = ObjectType::WeaponObject;
}

Weapon::Weapon(string name, string description, int id, int score, ObjectType type)
	: ObjectBase(name, description, id, score, type)
{
	_damage = _speed = 0.0;
}

Weapon::~Weapon()
{
}

double Weapon::getDamage()
{
	return _damage;
}

void Weapon::setDamage(double damage)
{
	_damage = damage;
}

double Weapon::getSpeed()
{
	return _speed;
}

void Weapon::setSpeed(double speed)
{
	_speed = speed;
}