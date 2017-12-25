/*
	Door.h
	Created By:		Justin LeCheminant
	Created On:		12-24-2017
	Last Modified:	12-24-2017

	Notes: A class that reprsents a door. This can be between rooms, a gate, anything that needs to be opened. It can also be locked.

*/

#pragma once

#include "stdafx.h"

#include "ObjectBase.h"

class Door: 
	public ObjectBase
{
public:
	Door();
	Door(int);
	~Door();

private:

};