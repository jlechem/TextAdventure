/*
	Door.cpp
	Created By:		Justin LeCheminant
	Created On:		12-24-2017
	Last Modified:	12-24-2017

	Notes: Implementation of the Door class.

*/

#include "stdafx.h"

#include "Door.h"

Door::Door()
	:ObjectBase()
{
	_type = ObjectType::DoorObject;
}

Door::Door(int id) 
	: ObjectBase(id)
{
	_type = ObjectType::DoorObject;
}

Door::~Door()
{
}