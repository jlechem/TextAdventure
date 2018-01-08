/*
	TakeCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class that represents a take command, take all, take X, etc

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class TakeCommand :
	public CommandInterface
{
public:
	TakeCommand();
	TakeCommand(string);
	TakeCommand(string, Player*);
	TakeCommand(string, Player*, Parser*);
	~TakeCommand();

	void process() override;

protected:
	void calculateValidity() override;

};