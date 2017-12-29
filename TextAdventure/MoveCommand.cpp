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

MoveCommand::MoveCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}


MoveCommand::~MoveCommand()
{
}

void MoveCommand::process()
{
	auto newDirection = Utilities::convertDirection(_command);

	_commandResult = "There is no exit " + _command;

	switch (_commandWords.size())
	{
		// single direction
		case 1:
			_commandResult = _player->Move(_command) ? _player->getCurrentRoom()->getLongDescription() : "There is no exit " + _command;
			break;

		case 2:
			//  this could be north east, south west, etc
			_commandResult = _player->Move(_commandWords[0] + " " + _commandWords[1]) ? _player->getCurrentRoom()->getLongDescription() : "There is no exit " + _command;
			break;

	}

	cout << endl << _commandResult << endl;

}

void MoveCommand::calculateValidity()
{
	_isValid = _commandWords.size() > 0 && _commandWords.size() < 4;
}