/*
	File:			HelpCommand.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-9-2018

	Notes:			A class that reprsents a help command and should print a help message.

*/

#pragma once

#include "CommandInterface.h"

class HelpCommand :
	public CommandInterface
{
public:
	HelpCommand();
	HelpCommand(string);
	HelpCommand(string, Player*);
	~HelpCommand();

	void process() override;

};