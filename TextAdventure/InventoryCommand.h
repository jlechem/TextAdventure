/*
	InventoryCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class used to hold game settings

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
	~InventoryCommand();

	void process();

protected:
	void calculateValidity();

};