/*
	ExamineCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents an examine command, examine X where X is an item in your inventory
*/

#pragma once

#include "CommandInterface.h"

class ExamineCommand :
	public CommandInterface
{
public:
	ExamineCommand();
	~ExamineCommand();
};

