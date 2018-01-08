/*
	TalkCommand.h
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	01-02-2018

	Notes: A class that reprsents a TalkCommand

*/

#pragma once

#include "CommandInterface.h"

#include "Player.h"

class TalkCommand :
	public CommandInterface
{
public:
	TalkCommand();
	TalkCommand(string);
	TalkCommand(string, Player *);
	TalkCommand(string, Player*, Parser*);
	~TalkCommand();

	void process();

protected:
	void calculateValidity();

private:

};