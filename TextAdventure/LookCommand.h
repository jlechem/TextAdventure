/*
	LookCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class that represents a look command. This can be the room they're in or an object in the room they're in.

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class LookCommand :
	public CommandInterface
{
public:
	LookCommand();
	LookCommand(string);
	LookCommand(string, Player*);
	~LookCommand();

	void process();

protected:
	void calculateValidity();

};