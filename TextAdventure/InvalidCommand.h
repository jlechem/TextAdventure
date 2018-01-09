/*
	File:			InvalidCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			A class that represents an InvalidCommand. This means the user typed in a command we don't understand.

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
	InvalidCommand(string,Player*);
	~InvalidCommand();

	void process() override;

};