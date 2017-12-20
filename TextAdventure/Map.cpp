/*
	Map.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Map class.

*/

#include "stdafx.h"
#include "Map.h"

/// <summary>
/// Initializes a new instance of the <see cref="Map"/> class.
/// </summary>
Map::Map()
{
}

/// <summary>
/// Initializes a new instance of the <see cref="Map"/> class.
/// </summary>
/// <param name="room">The room.</param>
Map::Map(shared_ptr<Room> room)
{
	_currentRoom = _startRoom = room;
}

/// <summary>
/// Finalizes an instance of the <see cref="Map"/> class.
/// </summary>
Map::~Map()
{
}
