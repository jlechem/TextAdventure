/*
	DropCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-21-2017
	Notes: Implementation of the DropCommand class.
*/

#include "stdafx.h"
#include "DropCommand.h"


DropCommand::DropCommand(): CommandInterface()
{
}

DropCommand::DropCommand(string command): CommandInterface(command)
{
}

DropCommand::DropCommand(string command, shared_ptr<Player> player)
{
}


DropCommand::~DropCommand()
{
}

void DropCommand::process()
{
	cout << endl << "DROP" << endl;
}

void DropCommand::calculateValidity()
{
}