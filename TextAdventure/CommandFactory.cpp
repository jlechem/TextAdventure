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

	// parse the command
	
	Parser* parser = new Parser();
	parser->parse(command);

	if (parser->getIsValid())
	{
		string initCommand = parser->getVerb();

		// command should be one word (look,move,take,drop,jump,etc)
		// based on this we need to return the correct command class
		if (Utilities::isLookCommand(initCommand))
		{
			commandPointer = make_unique<LookCommand>(command, player, parser);
		}
		else if (Utilities::isMoveCommand(initCommand))
		{
			commandPointer = make_unique<MoveCommand>(command, player, parser);
		}
		else if (Utilities::isTakeCommand(initCommand))
		{
			commandPointer = make_unique<TakeCommand>(command, player, parser);
		}
		else if (Utilities::isDropCommand(initCommand))
		{
			commandPointer = make_unique<DropCommand>(command, player, parser);
		}
		else if (Utilities::isExamineCommand(initCommand))
		{
			commandPointer = make_unique<ExamineCommand>(command, player, parser);
		}
		else if (Utilities::isExitCommand(initCommand))
		{
			commandPointer = make_unique<ExitCommand>(command, player, parser);
		}
		else if (Utilities::isInventoryCommand(initCommand))
		{
			commandPointer = make_unique<InventoryCommand>(command, player, parser);
		}
		else if (Utilities::isPutCommand(initCommand))
		{
			commandPointer = make_unique<PutCommand>(command, player, parser);
		}
		else if (Utilities::isOpenCommand(initCommand))
		{
			commandPointer = make_unique<OpenCommand>(command, player, parser);
		}
		else if (Utilities::isSaveCommand(command))
		{
			commandPointer = make_unique<SaveCommand>(command, player, parser);
		}
		else if (Utilities::isLoadCommand(command))
		{
			commandPointer = make_unique<LoadCommand>(command, player, parser);
		}
		else if (Utilities::isTalkCommand(command))
		{
			commandPointer = make_unique<TalkCommand>(command, player, parser);
		}
		else if (Utilities::isWearCommand(command))
		{
			commandPointer = make_unique<WearCommand>(command, player, parser);
		}
		else if (Utilities::isWieldCommand(command))
		{
			commandPointer = make_unique<WieldCommand>(command, player, parser);
		}
	}
	else
	{
		commandPointer = make_unique<InvalidCommand>(command, player);
	}

	// just drop back the pointer we made based on the command
	return std::move(commandPointer);

}