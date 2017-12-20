/*
	CommandInterface.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: This is an interface class that will get used for dependency injection. When a command is typed in the correct concrete
	implementation will be injected into the appropriate object that holds the command. This is most likely in the actual game loop.

*/

#pragma once

#include "stdafx.h"

class CommandInterface
{
public:
	CommandInterface();
	CommandInterface(string);
	~CommandInterface();

	virtual void process() = 0;
	
	string getCommad();
	void setCommand(string);

	void addWord(string);
	vector<string>& getWords();

	string getResult();

protected:
	bool _isValid;

	string _command;
	string _commandResult;

	vector<string> _commandWords;

	virtual void calculateValidity() = 0;

private:
		

};