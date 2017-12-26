/*
	ExamineCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: A class that represents an examine command, examine X where X is an item in your inventory

*/

#pragma once

#include "stdafx.h"

#include "CommandInterface.h"

class ExamineCommand :
	public CommandInterface
{
public:
	ExamineCommand();
	ExamineCommand(string);
	ExamineCommand(string, shared_ptr<Player>);
	~ExamineCommand();

	void process();

protected:
	void calculateValidity();

private:
	string examineItem(string name);

};