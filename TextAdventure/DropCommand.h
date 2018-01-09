/*
	File:			DropCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	1-9-2018

	Notes:			A class that represents a drop command, drop all, drop X, etc

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class DropCommand :
	public CommandInterface
{
public:
	DropCommand();
	DropCommand(string);
	DropCommand(string, Player*);
	DropCommand(string, Player*,Parser*);
	~DropCommand();
	void process() override;

};