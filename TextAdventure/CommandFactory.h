/*
	CommandFactory.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant

	Notes: Class to get the command object we want based on a command string

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"
#include "DropCommand.h"
#include "ExamineCommand.h"
#include "ExitCommand.h"
#include "FunCommand.h"
#include "HelpCommand.h"
#include "InvalidCommand.h"
#include "InventoryCommand.h"
#include "LoadCommand.h"
#include "LookCommand.h"
#include "MoveCommand.h"
#include "OpenCommand.h"
#include "PutCommand.h"
#include "SaveCommand.h"
#include "TalkCommand.h"
#include "TakeCommand.h"
#include "Utils.h"
#include "WearCommand.h"
#include "WieldCommand.h"

class CommandFactory
{
public:
	CommandFactory();
	~CommandFactory();

	static unique_ptr<CommandInterface> getCommand(string, Player*);

};