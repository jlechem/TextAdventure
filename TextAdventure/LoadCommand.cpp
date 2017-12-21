/*
	LoadCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: Implemenation of the LoadCommand class.
*/

#include "stdafx.h"
#include "LoadCommand.h"


LoadCommand::LoadCommand(): CommandInterface()
{
}

LoadCommand::LoadCommand(string command): CommandInterface(command)
{
}


LoadCommand::~LoadCommand()
{
}

void LoadCommand::process()
{
}

void LoadCommand::calculateValidity()
{
}
