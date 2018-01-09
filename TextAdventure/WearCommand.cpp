/*
	WearCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-9-2018

	Notes:			Implementation of the WearCommand class

*/

#include "stdafx.h"

#include "WearCommand.h"

WearCommand::WearCommand()
	: CommandInterface()	
{
}

WearCommand::WearCommand(string command)
	: CommandInterface(command) 
{
}

WearCommand::WearCommand(string command, Player * player)
	: CommandInterface(command,player) 
{
}

WearCommand::WearCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

WearCommand::~WearCommand()
{
}

void WearCommand::process()
{
	cout << endl << "WEAR" << endl;
}