/*
	CommandInterface.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		1-8-2018
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the CommandInterface class.

*/

#include "stdafx.h"

#include "CommandInterface.h"

CommandInterface::CommandInterface()
{
}

CommandInterface::CommandInterface(string command)
	: CommandInterface()
{
	_command = command;
}

CommandInterface::CommandInterface(string command, Player* player)
	: CommandInterface(command)
{
	_player = player;
}

CommandInterface::CommandInterface(string command, Player *player, Parser* parser)
	: CommandInterface(command, player)
{
	_parser = parser;
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