/*
	PutCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		12-27-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the PutCommand class.

*/

#include "stdafx.h"

#include "PutCommand.h"

PutCommand::PutCommand()
	: CommandInterface()
{
}

PutCommand::PutCommand(string command)
	: CommandInterface(command)
{
}

PutCommand::PutCommand(string command,Player* player)
	: CommandInterface(command,player) 
{
}

PutCommand::~PutCommand()
{
}

void PutCommand::process()
{
	calculateValidity();

	if (_isValid)
	{
		// do some validation
		if (_commandWords.size() < 4)
		{
			_commandResult = "Put what in what?";
		}
		else
		{
			string roomItem = "";
			string playerItem = "";

			auto foundRoomItem = _player->getCurrentRoom()->findItem(roomItem);

			if (foundRoomItem)
			{
				// find the item in the player
				auto foundPlayerItem = _player->dropItem(playerItem, false);

				// if we have it, then put in our foundItem
				if (foundPlayerItem)
				{
					// add the found player item to the room item
					foundRoomItem->addItem(std::move(foundPlayerItem));
					// since finding the room moves the poitner we need to put it back
					_player->getCurrentRoom()->addItem(std::move(foundRoomItem));
				}
			}
			else
			{
				_commandResult = "There is no X here";
			}
		}
	}
	else
	{
		_commandResult = "I don't know how to " + _command;
	}

	cout << endl << _commandResult << endl;

}

void PutCommand::calculateValidity()
{
	_isValid = _commandWords.size() < 4;
}