/*
	CommandFactory.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
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
	// create a pointer to our base class
	unique_ptr<CommandInterface> commandPointer = nullptr;

	// command should be one word (look,move,take,drop,jump,etc)
	// based on this we need to return the correct command class
	if (Utilities::isLookCommand(command))
	{
		commandPointer = make_unique<LookCommand>(command);
	}
	else if (Utilities::isMoveCommand(command))
	{
		commandPointer = make_unique<MoveCommand>(command);
	}
	else if (Utilities::isTakeCommand(command))
	{
		commandPointer = make_unique<TakeCommand>(command);
	}
	else if (Utilities::isDropCommand(command))
	{
		commandPointer = make_unique<DropCommand>(command);
	}
	else
	{
		// TODO: set to invalid command
	}

	// just drop back the pointer we made based on the command
	return std::move(commandPointer);

}