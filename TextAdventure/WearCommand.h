/*
	WearCommand.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-8-2018

	Notes: A class that reprsents a WearCommand

*/

#pragma once

#include "CommandInterface.h"

#include "Player.h"

class WearCommand :
	public CommandInterface
{
public:
	WearCommand();
	WearCommand(string);
	WearCommand(string,Player*);
	WearCommand(string, Player*, Parser*);
	~WearCommand();

	void process();

protected:
	void calculateValidity();

private:

};