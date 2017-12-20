/*
	CommandBase.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant
*/

#pragma once

#include "stdafx.h"

class CommandBase
{
public:
	CommandBase();
	~CommandBase();

	virtual void process() = 0;
	
	string getCommad();
	void setCommand(string);

	string getResult();

private:
	bool _isValid;
	
	string _command;
	string _commandResult;

	virtual void calculateValidity() = 0;

};