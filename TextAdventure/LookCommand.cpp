/*
	LookCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the LookCommand class.
*/

#include "stdafx.h"
#include "LookCommand.h"


LookCommand::LookCommand()
{
}

LookCommand::LookCommand(string command)
	:CommandInterface(command)
{
}

LookCommand::LookCommand(string command, shared_ptr<Player> player): CommandInterface(command,player)
{
}


LookCommand::~LookCommand()
{
}

void LookCommand::process()
{
	// first check the validity
	calculateValidity();

	if (_isValid)
	{

		// based on the size of the vector we can assume certain things
		switch (_commandWords.size())
		{
			// just a LOOK command, this prints the room description
		case 1:
			_commandResult = _player->getCurrentRoom()->getLongDescription();
			break;

		case 2:
			break;

		case 3:
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

void LookCommand::calculateValidity()
{
	auto size = _commandWords.size();
	_isValid = size > 0 && size < 4;
}