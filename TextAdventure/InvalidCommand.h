/*
	InvalidCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class that represents an InvalidCommand. This means the user typed in a command we don't understand.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class InvalidCommand :
	public CommandInterface
{
public:
	InvalidCommand();
	InvalidCommand(string);
	InvalidCommand(string,shared_ptr<Player>);
	~InvalidCommand();

	void process();

protected:
	void calculateValidity();

};