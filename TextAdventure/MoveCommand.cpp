/*
	MoveCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the MoveCommand class.

*/

#include "stdafx.h"

#include "MoveCommand.h"

MoveCommand::MoveCommand()
	: CommandInterface()
{
}

MoveCommand::MoveCommand(string command)
	: CommandInterface(command)
{
}

MoveCommand::MoveCommand(string command, shared_ptr<Player> player)
	: CommandInterface(command,player)
{
}


MoveCommand::~MoveCommand()
{
}

void MoveCommand::process()
{
	auto newDirection = Utilities::convertDirection(_command);

	switch (_commandWords.size())
	{
		// single direction
		case 1:
			_commandResult = _player->Move(_command) ? _player->getCurrentRoom()->getLongDescription() : "There is no exit " + _command;

			break;

		case 2:
			break;

		case 3:
			break;

		default:
			break;
	}

	cout << endl << _commandResult << endl;

}

void MoveCommand::calculateValidity()
{
	_isValid = _commandWords.size() > 0 && _commandWords.size() < 4;
}