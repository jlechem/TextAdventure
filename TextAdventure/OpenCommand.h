/*
	OpenCommand.h
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		12-27-2017
	Last Modified By:	Justin LeCheminant

	Notes: A class used to open an Item

*/

#pragma once

#include "CommandInterface.h"

class OpenCommand :
	public CommandInterface
{
public:
	OpenCommand();
	OpenCommand(string);
	OpenCommand(string, Player*);
	~OpenCommand();

	void process();

protected:
	void calculateValidity();
};