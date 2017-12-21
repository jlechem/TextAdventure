/*
	CommandInterface.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-21-2017
	Last Modified By:	Justin LeCheminant
	Notes:				Implementation of the CommandInterface class.
*/

#include "stdafx.h"
#include "CommandInterface.h"


CommandInterface::CommandInterface()
{
	 _player = make_shared<Player>();
	 _playerToActOn = make_shared<Player>();
	_objectToActOne = make_unique<Item>();
}

CommandInterface::CommandInterface(string command)
{
	_player = make_shared<Player>();
	_playerToActOn = make_shared<Player>();
	_objectToActOne = make_unique<Item>();
	_command = command;
	parseCommand();
}

CommandInterface::CommandInterface(string command, shared_ptr<Player> player)
{
	_player = player;
	_playerToActOn = make_shared<Player>();
	_objectToActOne = make_unique<Item>();
	_command = command;
	parseCommand();
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
	parseCommand();
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

shared_ptr<Player> CommandInterface::getPlayer()
{
	return _player;
}

void CommandInterface::setPlayer(shared_ptr<Player> player)
{
	_player = player;
}

shared_ptr<Player> CommandInterface::getPlayerToActOn()
{
	return _playerToActOn;
}

void CommandInterface::setPlayerToActOn(shared_ptr<Player> actor)
{
	_playerToActOn = actor;
}

unique_ptr<ObjectBase>& CommandInterface::getObjectToActOn()
{
	return _objectToActOne;
}

void CommandInterface::setObjectToActOn(unique_ptr<ObjectBase> object)
{
	_objectToActOne = std::move(object);
}

void CommandInterface::parseCommand()
{
	// tokenize the command based on spaces
	char delim = ' ';
	stringstream ss(_command);
	string item;

	_commandWords.clear();

	while (std::getline(ss, item, delim))
	{
		Utilities::toLower(item);
		_commandWords.push_back(item);
	}
}