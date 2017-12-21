/*
	MoveCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the MoveCommand class.

*/

#include "stdafx.h"
#include "MoveCommand.h"


MoveCommand::MoveCommand():CommandInterface()
{
}

MoveCommand::MoveCommand(string command)
	:CommandInterface(command)
{
}


MoveCommand::~MoveCommand()
{
}

void MoveCommand::process()
{
}

void MoveCommand::calculateValidity()
{
}