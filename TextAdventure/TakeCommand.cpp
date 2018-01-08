/*
	TakeCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
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
	// first check the validity
	calculateValidity();

	if (_isValid)
	{
		// based on the size of the vector we can assume certain things
		switch (_commandWords.size())
		{
		// just a TAKE command, this prints Take what?
		case 1:
			_commandResult = "Take what?";
			break;

		// TAKE X
		case 2:
			if (_commandWords[1] == "all")
			{
				auto result = _player->takeAllItems();
				_commandResult = !result.empty() ? result : "There's nothing here to take";
			}
			else
			{
				// use the single word to find in the room
				_commandResult = _player->addItem(_commandWords[1]) ? "You take the " + _commandWords[1] : "You don't see " + _commandWords[1];
			}
			
			break;

		default:
			// we could have any length of LOOK X Y ...... Z
			// we need to parse this somehow
			break;

		}
	}
	else
	{
		_commandResult = "I don't know how to " + _command;
	}

	// always print our result
	cout << endl << _commandResult << endl;

}

void TakeCommand::calculateValidity()
{
	auto size = _commandWords.size();
	_isValid = size > 0 && size < 4;
}