/*
	InvalidCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: Implementation of the InvalidCommand class.

*/

#include "stdafx.h"

#include "InvalidCommand.h"


InvalidCommand::InvalidCommand()
	: CommandInterface()
{
	_isValid = false;
}

InvalidCommand::InvalidCommand(string command)
	: CommandInterface(command)
{
	_isValid = false;
}


InvalidCommand::InvalidCommand(string command,Player* player)
	: CommandInterface(command,player)
{
	_isValid = false;
}

InvalidCommand::~InvalidCommand()
{
}

void InvalidCommand::process()
{
	// always print our result
	cout << "I don't know how to " << _command << endl;
}

void InvalidCommand::calculateValidity()
{
	// EMPTY: isValid is always false
}
