/*
	CommandInterface.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant
*/

#include "stdafx.h"
#include "CommandInterface.h"


CommandInterface::CommandInterface()
{
	 _player = make_shared<ActorBase>();
	 _playerToActOn = make_shared<ActorBase>();
	_objectToActOne = make_unique<Item>();
}

CommandInterface::CommandInterface(string command)
{
	_player = make_shared<ActorBase>();
	_playerToActOn = make_shared<ActorBase>();
	_objectToActOne = make_unique<Item>();
	_command = command;
}

CommandInterface::~CommandInterface()
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