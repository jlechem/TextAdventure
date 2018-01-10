/*
	File:			FunCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

	Notes:			Implemenation of the FunCommand class.

*/

#include "stdafx.h"

#include "FunCommand.h"

FunCommand::FunCommand()
	: CommandInterface()
{
}

FunCommand::FunCommand(string command)
	: CommandInterface(command)
{
}

FunCommand::FunCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

FunCommand::FunCommand(string command, Player* player, map<string, string> map)
	: CommandInterface(command, player)
{
	_map = map;
}

FunCommand::~FunCommand()
{
}

void FunCommand::process()
{
	// get the result from the map, if we got this far we know we have a valid command
	cout << endl << _map[_command] << endl;
}