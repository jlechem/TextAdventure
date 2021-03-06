/*
	Utils.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-29-2017
	Last Modified By:	Justin LeCheminant

	Notes: Static class with a bunch of utility functions in it

*/

#pragma once

#include "stdafx.h"

class Utilities
{
public:
	static Directions convertDirection(string);

	static bool isUnlockCommand(string);

	static bool isPutCommand(string command);

	static string convertDirection(Directions);

	static bool isDiagnosticCommand(string);

	static bool isFunCommand(string);

	static bool isMoveCommand(string);

	static bool isTakeCommand(string);

	static bool isLookCommand(string);

	static bool isDropCommand(string);

	static bool isItemCommand(string);

	static bool isInventoryCommand(string);

	static bool isSaveCommand(string);

	static bool isExitCommand(string);

	static bool isExamineCommand(string);

	static bool isOpenCommand(string);

	static bool isCloseCommand(string);

	static bool isLockCommand(string);

	static bool isKillCommand(string);

	static bool isActionCommand(string);

	static bool isClearCommand(string);

	static bool isLoadCommand(string);

	static bool isHelpCommand(string);

	static bool isWearCommand(string);

	static bool isWieldCommand(string);

	static bool isTalkCommand(string);

	static void toLower(string&);

	static void trim(string& );

	static void trimLeft(string&);

	static void trimRight(string&);

	static bool toBoolean(const string&);

private:
	// blocks anyone from making a default instance of this class
	Utilities();
};