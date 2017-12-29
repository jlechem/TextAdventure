/*
	OpenCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		12-27-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the OpenCommand class

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

OpenCommand::~OpenCommand()
{
}

void OpenCommand::process()
{
	// OPEN
	if (_commandWords.size() == 1)
	{
		_commandResult = "Open what?";
	}
	// OPEN X
	else if (_commandWords.size() == 2)
	{
		string itemToFind = _commandWords[1];

		// get the item to open
		auto itemToOpen = _player->dropItem(itemToFind,false);

		// check if we didnt find anything in OUR inventory, we need to check the room
		if (!itemToOpen)
		{

		}
		else
		{
			if (itemToOpen->getCanOpen())
			{

			}
			else
			{
				_commandResult = "You can't open that";
			}
		}
	}
	// could be anything, OPEN THE X
	else
	{
		_commandResult = "I don't know how to " + _command;
	}

	cout << endl << _commandResult << endl;

}

void OpenCommand::calculateValidity()
{
	_isValid = _commandWords.size() < 1;
}