#pragma once

#include "stdafx.h"

#include "Utils.h"

Directions ConvertDirection(std::string direction)
{
	Directions result = Directions::Invalid;

	if (direction == NORTH_SHORT || direction == NORTH)
	{
		result = Directions::North;
	}
	else if (direction == SOUTH_SHORT || direction == SOUTH)
	{
		result = Directions::South;
	} 
	else if (direction == EAST_SHORT || direction == EAST)
	{
		result = Directions::East;
	}
	else if (direction == WEST_SHORT || direction == WEST)
	{
		result = Directions::West;
	}
	else if (direction == NORTHEAST_SHORT || direction == NORTHEAST || direction == NORTHEAST_SPACE)
	{
		result = Directions::NorthEast;
	}
	else if (direction == SOUTHEAST_SHORT || direction == SOUTHEAST || direction == SOUTHEAST_SPACE)
	{
		result = Directions::SouthEast;
	}
	else if (direction == SOUTHWEST_SHORT || direction == SOUTHWEST || direction == SOUTHWEST_SPACE)
	{
		result = Directions::SouthWest;
	}
	else if (direction == NORTHWEST_SHORT || direction == NORTHWEST || direction == NORTHWEST_SPACE)
	{
		result = Directions::NorthWest;
	}
	else if (direction == UP_SHORT || direction == UP )
	{
		result = Directions::Up;
	}
	else if (direction == DOWN_SHORT || direction == DOWN)
	{
		result = Directions::Down;
	}

	return result;
}

Directions Utilities::convertDirectionStringToEnum(string direction)
{
	Directions result = Directions::Invalid;

	if (direction == "n" || direction == "north")
	{
		result = Directions::North;
	}
	else if (direction == "s" || direction == "south")
	{
		result = Directions::South;
	}
	else if (direction == "e" || direction == "east")
	{
		result = Directions::East;
	}
	else if (direction == "w" || direction == "west")
	{
		result = Directions::West;
	}
	else if (direction == "ne" || direction == "northeast" || direction == "north east")
	{
		result = Directions::NorthEast;
	}
	else if (direction == "se" || direction == "southeast" || direction == "south east")
	{
		result = Directions::SouthEast;
	}
	else if (direction == "sw" || direction == "southwest" || direction == "south west")
	{
		result = Directions::SouthWest;
	}
	else if (direction == "nw" || direction == "northwest" || direction == "north west")
	{
		result = Directions::NorthWest;
	}

	return result;
}