/*
	LookCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-22-2017

	Notes: Implemenation of the LookCommand class.

*/

#include "stdafx.h"

#include "LookCommand.h"

LookCommand::LookCommand()
	: CommandInterface()
{
}

LookCommand::LookCommand(string command)
	: CommandInterface(command)
{
}

LookCommand::LookCommand(string command,Player* player)
	: CommandInterface(command,player)
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

			// could be LOOK AT || LOOK ITEM
			case 2:
				if (_commandWords[1] == "at")
				{
					_commandResult = "Look at what?";
				}
				else
				{
					// use the single word to find in the room
					string itemToFind = _commandWords[1];

					auto item = _player->getCurrentRoom()->findItemDescription(itemToFind);

					_commandResult = item.size() > 0 ? item : "There's no " + itemToFind + " here";
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

void LookCommand::calculateValidity()
{
	auto size = _commandWords.size();
	_isValid = size > 0 && size < 4;
};