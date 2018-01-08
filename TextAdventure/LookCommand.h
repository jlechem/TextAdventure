/*
	LookCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

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
	LookCommand(string, Player*, Parser* );
	~LookCommand();

	void process() override;

protected:
	void calculateValidity() override;

};