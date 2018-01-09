/*
	File:			ExitCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			Implemenation of the ExitCommand class.

*/

#include "stdafx.h"

#include "ExitCommand.h"

ExitCommand::ExitCommand()
	: CommandInterface()
{
}

ExitCommand::ExitCommand(string command)
	: CommandInterface(command)
{
}

ExitCommand::ExitCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

ExitCommand::ExitCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

ExitCommand::~ExitCommand()
{
}

void ExitCommand::process()
{
	_player->setIsGameOver(true);
}