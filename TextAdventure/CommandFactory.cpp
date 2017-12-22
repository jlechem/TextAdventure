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

	string initCommand = "";

	// this is an entire sentence so we need to break it up and parse the words
	if ( !command.empty() )
	{
		vector<string>* commands = new vector<string>();

		// tokenize the command based on spaces
		char delim = ' ';
		stringstream ss(command);
		string item;

		commands->clear();

		while (std::getline(ss, item, delim))
		{
			Utilities::toLower(item);
			commands->push_back(item);
		}

		initCommand = (*commands)[0];

		delete commands;

	}
	
	// command should be one word (look,move,take,drop,jump,etc)
	// based on this we need to return the correct command class
	if (Utilities::isLookCommand(initCommand))
	{
		commandPointer = make_unique<LookCommand>(command, player);
	}
	else if (Utilities::isMoveCommand(initCommand))
	{
		commandPointer = make_unique<MoveCommand>(command, player);
	}
	else if (Utilities::isTakeCommand(initCommand))
	{
		commandPointer = make_unique<TakeCommand>(command, player);
	}
	else if (Utilities::isDropCommand(initCommand))
	{
		commandPointer = make_unique<DropCommand>(command, player);
	}
	else if (Utilities::isExamineCommand(initCommand))
	{
		commandPointer = make_unique<ExamineCommand>(command, player);
	}
	else if (Utilities::isExitCommand(initCommand))
	{
		commandPointer = make_unique<ExitCommand>(command, player);
	}
	else if (Utilities::isInventoryCommand(initCommand))
	{
		commandPointer = make_unique<InventoryCommand>(command, player);
	}
	// last case is always an invalid command
	else
	{
		commandPointer = make_unique<InvalidCommand>(command, player);
	}

	// just drop back the pointer we made based on the command
	return std::move(commandPointer);

}