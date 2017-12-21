/*
	SaveCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the SaveCommand class.
*/

#include "stdafx.h"
#include "SaveCommand.h"


SaveCommand::SaveCommand(): CommandInterface()
{
}

SaveCommand::SaveCommand(string command): CommandInterface(command)
{
}

SaveCommand::SaveCommand(string command, shared_ptr<Player> player) : CommandInterface(command, player)
{
}

SaveCommand::~SaveCommand()
{
}

void SaveCommand::process()
{
}

void SaveCommand::calculateValidity()
{
}
