/*
	File:						CloseCommand.h
	Created By:		Justin LeCheminant
	Created On:		1-9-2018
	Last Modified:	1-9-2018

	Notes:					A class for Closing an item

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class CloseCommand :
	public CommandInterface
{
public:
	CloseCommand();
	CloseCommand(string);
	CloseCommand(string,Player*);
	CloseCommand(string,Player*,Parser*);
	~CloseCommand();

	void process() override;

};