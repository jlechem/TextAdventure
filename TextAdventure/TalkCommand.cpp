/*
	TalkCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: Implementation of the TalkCommand class

*/

#include "stdafx.h"

#include "TalkCommand.h"

TalkCommand::TalkCommand()
	: CommandInterface()
{
}

TalkCommand::TalkCommand(string command)
	: CommandInterface(command)
{
}

TalkCommand::TalkCommand(string command, Player* player)
	: CommandInterface(command,player)
{
}

TalkCommand::TalkCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

TalkCommand::~TalkCommand()
{
}

void TalkCommand::process()
{
	calculateValidity();

	if (_commandWords.size() == 1)
	{
		_commandResult = "Say what?";
	}
	else
	{
		_commandResult = "TALK";
	}

	cout << endl <<  _commandResult << endl;

}

void TalkCommand::calculateValidity()
{
}