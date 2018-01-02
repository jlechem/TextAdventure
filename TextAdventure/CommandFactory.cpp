/*
	CommandFactory.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-29-2017
	Last Modified By:	Justin LeCheminant

	Notes: CommandFactory implementation

*/

#include "stdafx.h"

#include "CommandFactory.h"

CommandFactory::CommandFactory()
{
}

CommandFactory::~CommandFactory()
{
}

unique_ptr<CommandInterface> CommandFactory::getCommand(string command, Player* player)
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
	else if (Utilities::isFunCommand(command))
	{
		// TODO: get the map from the utilities class some how......
		map<string, string> m;
		m["jump"] = "You jump up and down";
		m["hum"] = "You hum that little ditty you like so much";
		m["sing"] = "You sing that song you love but the key seems to be off.....";
		m["dance"] = "You perform a waltz of epic proportions";
		m["rest"] = "You rest for a minute";
		m["sleep"] = "You lay down and sleep, refreshing";

		commandPointer = make_unique<FunCommand>(command, player,m);
	}
	else if (Utilities::isPutCommand(initCommand))
	{
		commandPointer = make_unique<PutCommand>(command, player);
	}
	else if (Utilities::isOpenCommand(initCommand))
	{
		commandPointer = make_unique<OpenCommand>(command, player);
	}
	else if (Utilities::isSaveCommand(command))
	{
		commandPointer = make_unique<SaveCommand>(command, player);
	}
	else if (Utilities::isLoadCommand(command))
	{
		commandPointer = make_unique<LoadCommand>(command, player);
	}
	else if (Utilities::isTalkCommand(command))
	{
		commandPointer = make_unique<TalkCommand>(command, player);
	}
	else if (Utilities::isWearCommand(command))
	{
		commandPointer = make_unique<WearCommand>(command, player);
	}
	else if (Utilities::isWieldCommand(command))
	{
		commandPointer = make_unique<WieldCommand>(command, player);
	}
	// last case is always an invalid command
	else
	{
		commandPointer = make_unique<InvalidCommand>(command, player);
	}

	// just drop back the pointer we made based on the command
	return std::move(commandPointer);

}