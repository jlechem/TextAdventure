/*
	DropCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-22-2017

	Notes: Implementation of the DropCommand class.

*/

#include "stdafx.h"

#include "DropCommand.h"

DropCommand::DropCommand()
	: CommandInterface()
{
}

DropCommand::DropCommand(string command)
	: CommandInterface(command)
{
}

DropCommand::DropCommand(string command,Player* player)
	: CommandInterface(command, player)
{
}

DropCommand::DropCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command,player,parser)
{
}

DropCommand::~DropCommand()
{
}

void DropCommand::process() 
{
	if (_parser->getNoun().empty())
	{
		_commandResult = "Drop what?";
	}
	else
	{
		if (_parser->getNoun() == "all")
		{
			auto result = _player->dropAllItems();
			_commandResult = !result.empty() ? result : "You don't have anything";
		}
		else
		{
			// use the single word to find in the room
			_commandResult = _player->dropItem(_parser->getNoun()) ? _parser->getNoun() + ": Dropped" : "You don't have the " + _parser->getNoun();
		}
	}
	// always print our result
	cout << endl << _commandResult << endl;
}