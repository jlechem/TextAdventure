/*
	File:				OpenCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		1-9-2018
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the OpenCommand class

*/

#include "stdafx.h"
#include "OpenCommand.h"

OpenCommand::OpenCommand()
	: CommandInterface()
{
}

OpenCommand::OpenCommand(string command)
	: CommandInterface(command)
{
}

OpenCommand::OpenCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

OpenCommand::OpenCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

OpenCommand::~OpenCommand()
{
}

void OpenCommand::process()
{
	// OPEN
	if (_parser->getNoun().empty() )
	{
		_commandResult = "Open what?";
	}
	// OPEN X
	else
	{
		bool fromPlayer = true;

		// get the item to open from the players inventory
		auto itemToOpen = _player->dropItem(_parser->getNoun(),false);

		// check if we didnt find anything in OUR inventory, we need to check the room
		if (!itemToOpen)
		{
			itemToOpen = _player->getCurrentRoom()->findItem(_parser->getNoun());
			fromPlayer = false;
		}

		// check if we found something in the room or on the player
		if (itemToOpen)
		{
			if (itemToOpen->getCanOpen())
			{
				itemToOpen->setIsOpen(true);
				_commandResult = itemToOpen->getName() + ": Opened";
			}
			else
			{
				_commandResult = _parser->getNoun() + ": ";
			}

			// OpenCommand, always put back what we found
			if (fromPlayer)
			{
				_player->addItem(std::move(itemToOpen));
			}
			else
			{
				_player->getCurrentRoom()->addItem(std::move(itemToOpen));
			}

		}
		else
		{
			_commandResult = "There's no " + _parser->getNoun() + " here";
		}
	}

	cout << endl << _commandResult << endl;

}