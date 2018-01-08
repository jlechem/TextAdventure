/*
	ExitCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

	Notes: A class that represents an Exit command. Like quit, q, or exit

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class ExitCommand :
	public CommandInterface
{
public:
	ExitCommand();
	ExitCommand(string);
	ExitCommand(string, Player*);
	ExitCommand(string, Player*, Parser*);
	~ExitCommand();
	
	void process() override;
	

protected:
	void calculateValidity() override;

};