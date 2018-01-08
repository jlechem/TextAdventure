/*
	LoadCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

	Notes: A class that represents a LoadCommand. The use loads a saved game from disk.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"
#include "Rooms.h"

class LoadCommand :
	public CommandInterface
{
public:
	LoadCommand();
	LoadCommand(string);
	LoadCommand(string, Player*);
	LoadCommand(string, Player*, Parser* );
	
	~LoadCommand(); 

	void process() override;
	
protected:
	void calculateValidity() override;

};