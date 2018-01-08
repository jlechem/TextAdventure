/*
	JumpCommand.h
	Created By:		Justin LeCheminant
	Created On:		1-8-2018
	Last Modified:	1-8-2018

	Notes: A class that represents a LoadCommand. The use loads a saved game from disk.

*/


#pragma once

#include "CommandInterface.h"

class JumpCommand :
	public CommandInterface
{
public:
	JumpCommand();
	JumpCommand(string, Player*);
	JumpCommand(string, Player*, Parser*);
	~JumpCommand();

	void process() override;

private:
	void calculateValidity() override;

};