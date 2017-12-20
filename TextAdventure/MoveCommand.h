/*
	MoveCommand.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: This class represents a command to move, like N, S, n, northwest, up, down, etc

*/

#pragma once

#include "CommandInterface.h"

class MoveCommand :
	public CommandInterface
{
public:
	MoveCommand();
	MoveCommand(string);
	~MoveCommand();

	void process();

private:
	void calculateValidity();

};

