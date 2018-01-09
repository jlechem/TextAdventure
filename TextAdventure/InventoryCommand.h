/*
	File:			InventoryCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			A class used to deal with inventory

*/


#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class InventoryCommand: public CommandInterface
{
public:
	InventoryCommand();
	InventoryCommand(string);
	InventoryCommand(string, Player*);
	InventoryCommand(string, Player*, Parser*);
	~InventoryCommand();

	void process();

};