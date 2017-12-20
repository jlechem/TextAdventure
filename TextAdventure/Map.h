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
	Map(shared_ptr<Room>);
	~Map();

private:
	shared_ptr<Room> _startRoom;
	shared_ptr<Room> _currentRoom;

};

