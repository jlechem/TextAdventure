/*
	CommandBase.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant
*/

#include "stdafx.h"
#include "CommandBase.h"


CommandBase::CommandBase()
{
}


CommandBase::~CommandBase()
{
}

void CommandBase::process()
{
}

string CommandBase::getCommad()
{
	return _command;
}

void CommandBase::setCommand(string command)
{
	_command = command;
}
