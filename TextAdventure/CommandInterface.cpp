/*
	CommandInterface.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-27-2017
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the CommandInterface class.

*/

#include "stdafx.h"

#include "CommandInterface.h"

CommandInterface::CommandInterface()
{
}

CommandInterface::CommandInterface(string command)
{
	_command = command;
	parseCommand();
}

CommandInterface::CommandInterface(string command, Player* player)
{
	_player = player;
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

Player* CommandInterface::getPlayer()
{
	return _player;
}

void CommandInterface::setPlayer(Player*player)
{
	_player = player;
}

Player* CommandInterface::getPlayerToActOn()
{
	return _playerToActOn;
}

void CommandInterface::setPlayerToActOn(Player* actor)
{
	_playerToActOn = actor;
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