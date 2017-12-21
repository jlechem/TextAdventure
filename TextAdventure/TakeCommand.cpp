/*
	TakeCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the TakeCommand class.
*/


#include "stdafx.h"
#include "TakeCommand.h"


TakeCommand::TakeCommand(): CommandInterface()
{
}

TakeCommand::TakeCommand(string command): CommandInterface(command)
{
}


TakeCommand::~TakeCommand()
{
}

void TakeCommand::process()
{
}

void TakeCommand::calculateValidity()
{
}