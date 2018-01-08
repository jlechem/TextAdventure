/*
	ExamineCommand.h
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

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
	ExamineCommand(string, Player*);
	ExamineCommand(string, Player*, Parser*);
	~ExamineCommand();

	void process() override;

protected:
	void calculateValidity() override;

private:
	string examineItem(string name);

};