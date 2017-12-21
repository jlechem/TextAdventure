/*
	FunCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017
	Notes: A class that represents a Fun command. Like jump, sing, dance, etc
*/

#pragma once

#include "CommandInterface.h"

class FunCommand :
	public CommandInterface
{
public:
	FunCommand();
	FunCommand(string);
	~FunCommand();

	void process();
	
protected:
	void calculateValidity();
};

