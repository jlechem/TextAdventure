/*
	WieldCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: Implementation of the WieldCommand class

*/

#include "stdafx.h"

#include "WieldCommand.h"

WieldCommand::WieldCommand()
	: CommandInterface()
{
}

WieldCommand::WieldCommand(string command)
	: CommandInterface(command)
{
}

WieldCommand::WieldCommand(string command, Player * player)
	: CommandInterface(command,player)
{
}

WieldCommand::WieldCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

WieldCommand::~WieldCommand()
{
}

void WieldCommand::process()
{
	calculateValidity();

	cout << endl << "WIELD" << endl;

}

void WieldCommand::calculateValidity()
{
}