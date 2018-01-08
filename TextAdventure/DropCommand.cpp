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
	// first check the validity
	calculateValidity();

	if (_isValid)
	{
		// based on the size of the vector we can assume certain things
		switch (_commandWords.size())
		{
		// just a DROP command, this prints Take what?
		case 1:
			_commandResult = "Drop what?";
			break;

		// DROP X
		// Could be DROP ALL
		case 2:
			if (_commandWords[1] == "all")
			{
				auto result = _player->dropAllItems();
				_commandResult = !result.empty() ? result : "You don't have anything";
			}
			else
			{
				// use the single word to find in the room
				_commandResult = _player->dropItem(_commandWords[1]) ? "You drop the " + _commandWords[1] : "You don't have the " + _commandWords[1];
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

void DropCommand::calculateValidity()
{
	auto size = _commandWords.size();
	_isValid = size > 0 && size < 4;
}