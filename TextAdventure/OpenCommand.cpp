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
		// check the player and see if they opened the damn thing
		string playerResult = _player->openItem(_parser->getNoun());

		// empty means something happened so do the room
		_commandResult = playerResult.empty() ?
			_commandResult = _player->getCurrentRoom()->openItem(_parser->getNoun()) :
			playerResult;
	}

	cout << endl << _commandResult << endl;

}