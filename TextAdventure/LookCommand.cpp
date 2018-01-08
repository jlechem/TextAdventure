/*
	LookCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

	Notes: Implemenation of the LookCommand class.

*/

#include "stdafx.h"

#include "LookCommand.h"

LookCommand::LookCommand()
	: CommandInterface()
{
}

LookCommand::LookCommand(string command)
	: CommandInterface(command)
{
}

LookCommand::LookCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}
 
LookCommand::LookCommand(string command, Player * player,Parser* parser)
	: CommandInterface(command, player, parser)
{
}

LookCommand::~LookCommand()
{
}

void LookCommand::process()
{
	// first check if we just did look, this is just a verb no noun and no articles
	if ( _parser->getNoun().empty() )
	{
		_commandResult = _player->getCurrentRoom()->getLongDescription();
	}
	else if ( !_parser->getNoun().empty())
	{
		auto item = _player->getCurrentRoom()->findItemDescription(_parser->getNoun());

		_commandResult = item.size() > 0 ? item : "There's no " + _parser->getNoun() + " here";
	}
	else
	{
		_commandResult = "I don't know how to " + _command;
	}

	// always print our result
	cout << endl << _commandResult << endl;

}

void LookCommand::calculateValidity()
{
};