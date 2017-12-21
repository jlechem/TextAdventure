/*
	LoadCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class that represents a LoadCommand. The use loads a saved game from disk.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class LoadCommand :
	public CommandInterface
{
public:
	LoadCommand();
	LoadCommand(string);
	LoadCommand(string, shared_ptr<Player>);
	~LoadCommand(); 

	void process();
	
protected:
	void calculateValidity();

};