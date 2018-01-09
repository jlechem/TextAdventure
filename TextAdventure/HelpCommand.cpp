/*
	HelpCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: Implementation of the HelpCommand class.

*/

#include "stdafx.h"

#include "HelpCommand.h"

HelpCommand::HelpCommand()
	: CommandInterface()
{
}

HelpCommand::HelpCommand(string command)
	: CommandInterface(command)
{
}

HelpCommand::HelpCommand(string command, Player* player)
	: CommandInterface(command,player) 
{
}

HelpCommand::~HelpCommand()
{
}

void HelpCommand::process()
{
}