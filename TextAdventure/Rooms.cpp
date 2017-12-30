/*
	Rooms.cpp
	Created By:		Justin LeCheminant
	Created On:		12-29-2017
	Last Modified:	12-29-2017

	Notes: Implemenation of the Rooms class.

*/

#include "stdafx.h"

#include "Rooms.h"

Rooms::Rooms()
{
}

Rooms::~Rooms()
{
}

Rooms& Rooms::getInstance()
{
	static Rooms instance;
	return instance;
}

vector<Room*>& Rooms::getRooms()
{
	return s_rooms;
}
