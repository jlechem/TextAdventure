/*
	FunCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

	Notes: Implemenation of the FunCommand class.

*/

#include "stdafx.h"

#include "FunCommand.h"

FunCommand::FunCommand()
	: CommandInterface()
{
	_isValid = true;
}

FunCommand::FunCommand(string command)
	: CommandInterface(command)
{
	_isValid = true;
}

FunCommand::FunCommand(string command,Player* player)
	: CommandInterface(command,player)
{
	_isValid = true;
}

FunCommand::FunCommand(string command, Player* player, map<string, string> map)
	: CommandInterface(command, player)
{
	_isValid = true;
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

void FunCommand::calculateValidity()
{
	// fun commands are always true since all we have to do is get the result from the map
}