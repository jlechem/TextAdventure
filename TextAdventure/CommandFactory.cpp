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
unique_ptr<CommandInterface> CommandFactory::getCommand(string command, shared_ptr<Player> player)
{
	// create a pointer to our base class
	unique_ptr<CommandInterface> commandPointer = nullptr;

	// always get commands in tolower
	Utilities::toLower(command);

	// command should be one word (look,move,take,drop,jump,etc)
	// based on this we need to return the correct command class
	if (Utilities::isLookCommand(command))
	{
		commandPointer = make_unique<LookCommand>(command, player);
	}
	else if (Utilities::isMoveCommand(command))
	{
		commandPointer = make_unique<MoveCommand>(command, player);
	}
	else if (Utilities::isTakeCommand(command))
	{
		commandPointer = make_unique<TakeCommand>(command, player);
	}
	else if (Utilities::isDropCommand(command))
	{
		commandPointer = make_unique<DropCommand>(command, player);
	}
	else if (Utilities::isExamineCommand(command))
	{
		commandPointer = make_unique<ExamineCommand>(command, player);
	}
	else if (Utilities::isExitCommand(command))
	{
		commandPointer = make_unique<ExitCommand>(command, player);
	}
	// last case is always an invalid command
	else
	{
		commandPointer = make_unique<InvalidCommand>(command, player);
	}

	// just drop back the pointer we made based on the command
	return std::move(commandPointer);

}