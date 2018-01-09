/*
	File:			InvalidCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			Implementation of the InvalidCommand class.

*/

#include "stdafx.h"

#include "InvalidCommand.h"


InvalidCommand::InvalidCommand()
	: CommandInterface()
{
}

InvalidCommand::InvalidCommand(string command)
	: CommandInterface(command)
{
}


InvalidCommand::InvalidCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

InvalidCommand::~InvalidCommand()
{
}

void InvalidCommand::process()
{
	// always print our result
	cout << "I don't know how to " << _command << endl;
}