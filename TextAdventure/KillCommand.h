/*
	File:			KillCommand.h
	Created By:		Justin LeCheminant
	Created On:		1-26-2018
	Last Modified:	1-26-2018

	Notes:			A class for fighting enemies

*/

#pragma once

#include "CommandInterface.h"

class KillCommand :
	public CommandInterface
{
public:
	KillCommand();
	KillCommand(string);
	KillCommand(string, Player*);
	KillCommand(string, Player*, Parser*);
	~KillCommand();

	void process() override;

};