/*
	CommandFactory.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: CommandFactory implementation

*/

#include "stdafx.h"
#include "CommandFactory.h"

/// <summary>
/// Initializes a new instance of the <see cref="CommandFactory"/> class.
/// </summary>
CommandFactory::CommandFactory()
{
}

/// <summary>
/// Finalizes an instance of the <see cref="CommandFactory"/> class.
/// </summary>
CommandFactory::~CommandFactory()
{
}

/// <summary>
/// Gets the command.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>
unique_ptr<CommandInterface> CommandFactory::getCommand(string command)
{
	// command should be one word (look,move,take,drop,jump,etc)
	// based on this we need to return the correct command class
	if (Utilities::isLookCommand(command))
	{
		return make_unique<LookCommand>(command);
	}
	else if (Utilities::isMoveCommand(command))
	{
		return make_unique<LookCommand>(command);
	}
	else
	{
		return make_unique<LookCommand>(command);
	}
}