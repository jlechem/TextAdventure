/*
	FunCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the FunCommand class.
*/

#include "stdafx.h"
#include "FunCommand.h"

FunCommand::FunCommand(): CommandInterface()
{
}

FunCommand::FunCommand(string command): CommandInterface(command)
{
}


FunCommand::~FunCommand()
{
}

void FunCommand::process()
{
}

void FunCommand::calculateValidity()
{
}