/*
	InventoryCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-22-2017
	Last Modified:	1-9-2018

	Notes: Implementation of the InventoryCommand class.

	*/


#include "stdafx.h"

#include "InventoryCommand.h"

InventoryCommand::InventoryCommand()
	: CommandInterface()
{
}

InventoryCommand::InventoryCommand(string command)
	: CommandInterface(command)
{
}

InventoryCommand::InventoryCommand(string command,Player* player)
	: CommandInterface(command,player)
{
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