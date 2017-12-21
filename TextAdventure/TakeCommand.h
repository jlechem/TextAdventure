/*
	TakeCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents a take command, take all, take X, etc
*/

#pragma once

#include "stdafx.h"
#include "CommandInterface.h"

class TakeCommand :
	public CommandInterface
{
public:
	TakeCommand();
	~TakeCommand();
};

