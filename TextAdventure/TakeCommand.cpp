/*
	File:			TakeCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018
	Notes: Implemenation of the TakeCommand class.
*/


#include "stdafx.h"

#include "TakeCommand.h"

TakeCommand::TakeCommand()
	: CommandInterface()
{
}

TakeCommand::TakeCommand(string command)
	: CommandInterface(command)
{
}

TakeCommand::TakeCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

TakeCommand::TakeCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

TakeCommand::~TakeCommand()
{
}

void TakeCommand::process()
{
	if (_parser->getNoun().empty())
	{
		_commandResult = "Take what?";
	}
	else
	{
		if (_parser->getNoun() == "all")
		{
			auto result = _player->takeAllItems();
			_commandResult = !result.empty() ? result : "There's nothing here to take";
		}
		else
		{
			// use the single word to find in the room
			_commandResult = _player->addItem(_parser->getNoun()) ? _parser->getNoun() + ": Taken" : "You don't see " + _parser->getNoun();
		}
	}

	// always print our result
	cout << endl << _commandResult << endl;

}