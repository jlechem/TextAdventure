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
		// get the item to open
		auto itemToOpen = _player->dropItem(_parser->getNoun(),false);

		// check if we didnt find anything in OUR inventory, we need to check the room
		if (!itemToOpen)
		{
			itemToOpen = _player->getCurrentRoom()->findItem(_parser->getNoun());
		}

		// check if we found something in the room or on the player
		if (itemToOpen)
		{
			if (itemToOpen->getCanOpen())
			{
				// TODO: OpenCommand, always put back what we found

			}
			else
			{
				_commandResult = "You can't open that";
			}
		}
		else
		{
			_commandResult = "I don't know how to " + _command;
		}
	}

	cout << endl << _commandResult << endl;

}