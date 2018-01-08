/*
	InventoryCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-22-2017
	Last Modified:	1-8-2018

	Notes: Implementation of the InventoryCommand class.

	*/


#include "stdafx.h"

#include "InventoryCommand.h"

InventoryCommand::InventoryCommand()
	: CommandInterface()
{
	_isValid = true;
}

InventoryCommand::InventoryCommand(string command)
	: CommandInterface(command)
{
	_isValid = true;
}

InventoryCommand::InventoryCommand(string command,Player* player)
	: CommandInterface(command,player)
{
	_isValid = true;
}

InventoryCommand::InventoryCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

InventoryCommand::~InventoryCommand()
{
}

void InventoryCommand::process()
{
	_player->printInventory();
}

void InventoryCommand::calculateValidity()
{
	// this is a simple command, we just need to print inventory, so the isValid is always true
}