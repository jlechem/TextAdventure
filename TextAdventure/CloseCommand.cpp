/*
	File:			CloseCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-10-2018

	Notes:			Implementation of the CloseCommand class

*/

#include "stdafx.h"

#include "CloseCommand.h"

CloseCommand::CloseCommand()
	: CommandInterface()
{
}

CloseCommand::CloseCommand(string command)
	: CommandInterface(command)
{
}

CloseCommand::CloseCommand(string command, Player * player)
	: CommandInterface(command,player)
{
}

CloseCommand::CloseCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command,player,parser)
{
}

CloseCommand::~CloseCommand()
{
}

void CloseCommand::process()
{
	auto itemToClose = _parser->getNoun();

	// empty CLOSE command
	if (itemToClose.empty())
	{
		_commandResult = "Close what?";
	}
	else
	{
		// get the item to close
		auto result = _player->closeItem(itemToClose);

		if (result)
		{
			_commandResult = itemToClose + ": Closed";
		}
		else
		{
			if (_player->getItemErrorMessage() == "Not found")
			{
				_commandResult = _player->getCurrentRoom()->closeItem(itemToClose) ?
					itemToClose + ": Closed" :
					itemToClose + ": " + _player->getCurrentRoom()->getItemErrorMessage();
			}
		}
	}

	cout << endl << _commandResult << endl;

}