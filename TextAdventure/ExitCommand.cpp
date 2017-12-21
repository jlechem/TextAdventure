/*
	ExitCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the ExitCommand class.
*/

#include "stdafx.h"
#include "ExitCommand.h"


ExitCommand::ExitCommand(): CommandInterface()
{
}

ExitCommand::ExitCommand(string command): CommandInterface(command)
{
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::process()
{
}

void ExitCommand::calculateValidity()
{
}
