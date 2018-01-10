/*
	File:			CloseCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-9-2018

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
	// TODO: implement the close command
	cout << endl << _commandResult << endl;
}