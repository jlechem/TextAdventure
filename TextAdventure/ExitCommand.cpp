/*
	ExitCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-22-2017

	Notes: Implemenation of the ExitCommand class.

*/

#include "stdafx.h"

#include "ExitCommand.h"

ExitCommand::ExitCommand()
	: CommandInterface()
{
	_isValid = true;
}

ExitCommand::ExitCommand(string command)
	: CommandInterface(command)
{
	_isValid = true;
}

ExitCommand::ExitCommand(string command, shared_ptr<Player> player)
	: CommandInterface(command,player)
{
	_isValid = true;
}

ExitCommand::~ExitCommand()
{
}

void ExitCommand::process()
{
	_player->setIsGameOver(true);
}

void ExitCommand::calculateValidity()
{
}
