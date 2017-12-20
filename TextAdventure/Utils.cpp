#pragma once

#include "stdafx.h"

#include "Utils.h"

Directions ConvertDirection(std::string direction)
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