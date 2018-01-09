/*
	File:			JumpCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-9-2018

	Notes:			Implemenation of the JumpCommand class.

*/


#include "stdafx.h"

#include "JumpCommand.h"

JumpCommand::JumpCommand()
	: CommandInterface()
{
}

JumpCommand::JumpCommand(string command,Player* player)
	: CommandInterface(command, player)
{
}

JumpCommand::JumpCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

JumpCommand::~JumpCommand()
{
}

void JumpCommand::process()
{
	cout << endl << "You jump up and down" << endl;
}