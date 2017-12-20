/*
	CommandInterface.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant
*/

#include "stdafx.h"
#include "CommandInterface.h"


CommandInterface::CommandInterface()
{
}

CommandInterface::CommandInterface(string command)
{
	_command = command;
}


CommandInterface::~CommandInterface()
{
}

void CommandInterface::process()
{
}

string CommandInterface::getCommad()
{
	return _command;
}

void CommandInterface::setCommand(string command)
{
	_command = command;
}

void CommandInterface::addWord(string word)
{
	_commandWords.push_back( word );
}

vector<string>& CommandInterface::getWords()
{
	return _commandWords;
}

string CommandInterface::getResult()
{
	return _commandResult;
}