/*
	LookCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the LookCommand class.
*/

#include "stdafx.h"
#include "LookCommand.h"


LookCommand::LookCommand()
{
}

LookCommand::LookCommand(string command)
	:CommandInterface(command)
{
}


LookCommand::~LookCommand()
{
}

void LookCommand::process()
{
}

void LookCommand::calculateValidity()
{
	_isValid = false;
}