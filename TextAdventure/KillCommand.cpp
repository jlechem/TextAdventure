/*
	File:			KillCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		1-26-2018
	Last Modified:	1-26-2018

	Notes:			Implementation of the KillCommand class

*/
#include "stdafx.h"

#include "KillCommand.h"

KillCommand::KillCommand()
	: CommandInterface()
{
}

KillCommand::KillCommand(string command)
	: CommandInterface(command)
{
}

KillCommand::KillCommand(string command, Player * player)
	: CommandInterface(command, player)
{
}

KillCommand::KillCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

KillCommand::~KillCommand()
{
}

void KillCommand::process()
{
	if (_parser->getNoun().empty())
	{
		_commandResult = "Kill what?";
	}
	else
	{
		auto opponent = nullptr;

		auto weapon = nullptr;




	}

	cout << endl << _commandResult << endl;

}
