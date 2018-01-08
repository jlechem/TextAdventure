/*
	MoveCommand.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		1-8-2018
	Last Modified By:	Justin LeCheminant

	Notes: This class represents a command to move, like N, S, n, northwest, up, down, etc

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class MoveCommand :
	public CommandInterface
{
public:
	MoveCommand();
	MoveCommand(string);
	MoveCommand(string, Player*);
	MoveCommand(string, Player*, Parser*);
	~MoveCommand();

	void process() override;

protected:
	void calculateValidity() override;

};

