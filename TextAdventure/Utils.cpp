/*
	Utilis.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-25-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Utilities class.

*/

#pragma once

#include "stdafx.h"

#include "Utils.h"

Utilities::Utilities()
{
}

Directions Utilities::convertDirection(string direction)
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

bool Utilities::isKillCommand(string command)
{
	return command == "kill" || command == "fight";
}

bool Utilities::isFunCommand(string command)
{
	/*
	_funCommands["jump"] = "You jump up and down";
	_funCommands["hum"] = "You hum that little ditty you like so much";
	_funCommands["sing"] = "You sing that song you love but the key seems to be off.....";
	_funCommands["dance"] = "You perform a waltz of epic proportions";
	_funCommands["rest"] = "You rest for a minte";
	_funCommands["sleep"] = "You lay down and sleep, refreshing";
	*/

	return	command == "jump" ||
			command == "hum" ||
			command == "sing" ||
			command == "dance" ||
			command == "rest" ||
			command == "sleep";
}

bool Utilities::isActionCommand(string command)
{
	return	isKillCommand(command) ||
		isDropCommand(command) ||
		isTakeCommand(command);
}

bool Utilities::isClearCommand(string command)
{
	return command == "cls" || command == "clear";
}

bool Utilities::isLoadCommand(string command)
{
	return command == "load";
}

bool Utilities::isHelpCommand(string command)
{
	return command == "help" || command == "h";
}

bool Utilities::isWearCommand(string command)
{
	return command == "wear";
}

bool Utilities::isWieldCommand(string command)
{
	return command == "wield";
}

bool Utilities::isTalkCommand(string command)
{
	return command == "talk" || command == "say";
}

void Utilities::toLower(string& value)
{
	transform(value.begin(), value.end(), value.begin(), tolower);
}

bool Utilities::isMoveCommand(string command)
{
	return
		command == "north" ||
		command == "south" ||
		command == "east" ||
		command == "west" ||
		command == "n" ||
		command == "e" ||
		command == "s" ||
		command == "w" ||
		command == "northeast" ||
		command == "northwest" ||
		command == "southeast" ||
		command == "southwest" ||
		command == "ne" ||
		command == "nw" ||
		command == "se" ||
		command == "sw" ||
		command == "up" ||
		command == "u" ||
		command == "down" ||
		command == "d";
}

bool Utilities::isTakeCommand(string command)
{
	return command == "take";
}

bool Utilities::isLookCommand(string command)
{
	return command == "look" || command == "l";
}

bool Utilities::isDropCommand(string command)
{
	return command == "drop";
}

bool Utilities::isItemCommand(string command)
{
	return false;
}

bool Utilities::isInventoryCommand(string command)
{
	return	command == "i" ||
		command == "inventory";
}

bool Utilities::isSaveCommand(string command)
{
	return command == "save";
}

bool Utilities::isExitCommand(string command)
{
	return	command == "exit" ||
		command == "quit" ||
		command == "q";
}

bool Utilities::isExamineCommand(string command)
{
	return command == "examine";
}

bool Utilities::isOpenCommand(string command)
{
	return command == "open";
}

bool Utilities::isCloseCommand(string command)
{
	return command == "close";
}

bool Utilities::isLockCommand(string command)
{
	return command == "lock";
}

bool Utilities::isUnlockCommand(string command)
{
	return command == "unlock";
}

bool Utilities::isPutCommand(string command)
{
	return command == "put";
}

string Utilities::convertDirection(Directions direction)
{
	string result = "";

	switch (direction)
	{
		case North:
			result = "North";
			break;

		case South:
			result = "South";
			break;

		case East:
			result = "East";
			break;

		case West:
			result = "West";
			break;

		case NorthWest:
			result = "North West";
			break;

		case NorthEast:
			result = "North East";
			break;

		case SouthEast:
			result = "South East";
			break;

		case SouthWest:
			result = "South West";
			break;

		case Up:
			result = "Up";
			break;

		case Down:
			result = "Down";
			break;
	}

	return result;

}