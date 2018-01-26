/*
	WieldCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-9-2018

	Notes:			Implementation of the WieldCommand class

*/

#include "stdafx.h"

#include "WieldCommand.h"

WieldCommand::WieldCommand()
	: CommandInterface()
{
}

WieldCommand::WieldCommand(string command)
	: CommandInterface(command)
{
}

WieldCommand::WieldCommand(string command, Player * player)
	: CommandInterface(command,player)
{
}

WieldCommand::WieldCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

WieldCommand::~WieldCommand()
{
}

void WieldCommand::process()
{
	if (_parser->getNoun().empty())
	{
		_commandResult = "Wield what?";
	}
	else
	{
		// find the item in our inventory to wield
		auto item = _player->findItem(_parser->getNoun());

		if (item)
		{
			// check if we can wield this item

			// always put it back
			_player->addItem(std::move(item));
		}

	}

	cout << endl << _commandResult << endl;

}