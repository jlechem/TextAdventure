/*
	Map.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Class that represents a map in the game.

*/

#pragma once

#include "stdafx.h"

#include "Room.h"

class Map
{
public:
	Map();
	Map(Room*);
	~Map();

private:
	Room* _startRoom;
	Room* _currentRoom;

};

