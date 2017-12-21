/*
	SaveCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: Class that represents a save command, ie when the user saves their game.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class SaveCommand :
	public CommandInterface
{
public:
	SaveCommand();
	SaveCommand(string);
	SaveCommand(string, shared_ptr<Player>);
	~SaveCommand(); 
		
	void process();

protected:
	void calculateValidity();

};

