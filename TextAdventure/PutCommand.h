/*
	PutCommand.h
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		12-27-2017
	Last Modified By:	Justin LeCheminant

	Notes: A class used to put an item into another item, PUT X in Y

*/

#pragma once

#include "CommandInterface.h"

class PutCommand :
	public CommandInterface
{
public:
	PutCommand();
	PutCommand(string);
	PutCommand(string, shared_ptr<Player>);
	~PutCommand();

	void process(); 

protected:
	void calculateValidity();

};