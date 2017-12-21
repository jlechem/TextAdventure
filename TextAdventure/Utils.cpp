/*
	Utilis.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Utilities class.

*/

#pragma once

#include "stdafx.h"

#include "Utils.h"

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

/// <summary>
/// Determines whether [is kill command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is kill command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isKillCommand(string command)
{
	return command == "kill" || command == "fight";
}

/// <summary>
/// Determines whether [is fun command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is fun command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isFunCommand(string command)
{
	/*auto result = _funCommands.find(command);

	return result != _funCommands.end();*/
	return false;
}

/// <summary>
/// Determines whether [is action command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is action command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isActionCommand(string command)
{
	return	isKillCommand(command) ||
		isDropCommand(command) ||
		isTakeCommand(command);
}

/// <summary>
/// Determines whether [is clear command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is clear command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isClearCommand(string command)
{
	return command == "cls" || command == "clear";
}

/// <summary>
/// Converts the value to all lower case.
/// </summary>
/// <param name="value">The value.</param>
/// <returns></returns>
void Utilities::toLower(string& value)
{
	transform(value.begin(), value.end(), value.begin(), tolower);
}

/// <summary>
/// Determines whether [is move command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is move command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
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
		command == "sw";
}

/// <summary>
/// Determines whether [is take command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is take command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isTakeCommand(string command)
{
	return command == "take";
}

/// <summary>
/// Determines whether [is look command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is look command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isLookCommand(string command)
{
	return command == "look" || command == "l";
}

/// <summary>
/// Determines whether [is drop command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is drop command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isDropCommand(string command)
{
	return command == "drop";
}

/// <summary>
/// Determines whether [is item command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is item command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isItemCommand(string command)
{
	return false;
}

/// <summary>
/// Determines whether [is inventory command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is inventory command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isInventoryCommand(string command)
{
	return	command == "i" ||
		command == "inventory";
}

/// <summary>
/// Determines whether [is save command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is save command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isSaveCommand(string command)
{
	return command == "save";
}

/// <summary>
/// Determines whether [is exit command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is exit command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isExitCommand(string command)
{
	return	command == "exit" ||
		command == "quit" ||
		command == "q";
}

/// <summary>
/// Determines whether [is examine command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is examine command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isExamineCommand(string command)
{
	return	command == "examine";
}

/// <summary>
/// Determines whether [is open command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is open command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isOpenCommand(string command)
{
	// TODO: implement isOpenCommand
	return false;
}

/// <summary>
/// Determines whether [is close command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is close command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isCloseCommand(string command)
{
	// TODO: implement isCloseCommand
	return false;
}

/// <summary>
/// Determines whether [is lock command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is lock command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isLockCommand(string command)
{
	// TODO: implement isLockCommand
	return false;
}

/// <summary>
/// Determines whether [is unlock command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is unlock command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Utilities::isUnlockCommand(string command)
{
	// TODO: implement isUnlockCommand
	return false;
}

/// <summary>
/// Converts the direction.
/// </summary>
/// <param name="direction">The direction.</param>
/// <returns></returns>
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

	}

	return result;

}