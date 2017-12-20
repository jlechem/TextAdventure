/*
	Utils.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: Static class with a bunch of utility functions in it

*/

#pragma once

#include "stdafx.h"

class Utilities
{
public:
	static Directions convertDirection(string direction);

	static bool isFunCommand(string);

	static bool isMoveCommand(string);

	static bool isTakeCommand(string);

	static bool isLookCommand(string);

	static bool isDropCommand(string);

	static bool isItemCommand(string);

	static bool isInventoryCommand(string);

	static bool isSaveCommand(string);

	static bool isExitCommand(string);

	static bool isKillCommand(string);

	static bool isActionCommand(string);

	static bool isClearCommand(string);

};