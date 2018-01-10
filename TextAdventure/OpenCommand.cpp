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
	if (_parser->getNoun().empty())
	{
		_commandResult = "Open what?";
	}
	// OPEN X
	else
	{
		bool openResult = _player->openItem(_parser->getNoun());

		if (openResult)
		{
			_commandResult = _parser->getNoun() + ": Opened";
		}
		else
		{
			// first check the error message, so we need to know if we need to check the room
			if (_player->getItemErrorMessage() != "Not found")
			{
				_commandResult = _parser->getNoun() + ": " + _player->getItemErrorMessage();
			}
			else
			{
				_commandResult = _player->getCurrentRoom()->openItem(_parser->getNoun()) ? 
					_parser->getNoun() + ": Opened" : 
					_parser->getNoun() + ": " + _player->getCurrentRoom()->getItemErrorMessage();
			}
		}
	}

	cout << endl << _commandResult << endl;
	
}