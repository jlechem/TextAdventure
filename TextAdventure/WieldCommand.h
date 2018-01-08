/*
	WieldCommand.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-8-2018

	Notes: A class used for a WieldCommand

*/

#pragma once

#include "CommandInterface.h"

class WieldCommand :
	public CommandInterface
{
public:
	WieldCommand();
	WieldCommand(string);
	WieldCommand(string,Player*);
	WieldCommand(string, Player*, Parser*);
	~WieldCommand();

	void process();

protected:
	void calculateValidity();

private:

};