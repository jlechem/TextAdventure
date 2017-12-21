/*
	DropCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents a drop command, drop all, drop X, etc
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
	~DropCommand();
	void process();

protected:
	void calculateValidity();

private:

};