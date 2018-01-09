/*
	MoveCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		1-9-2018
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the MoveCommand class.

*/

#include "stdafx.h"

#include "MoveCommand.h"

MoveCommand::MoveCommand()
	: CommandInterface()
{
}

MoveCommand::MoveCommand(string command)
	: CommandInterface(command)
{
}

MoveCommand::MoveCommand(string command,Player* player)
	: CommandInterface(command,player)
{
}

MoveCommand::MoveCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}


MoveCommand::~MoveCommand()
{
}

void MoveCommand::process()
{
	// check if the verb is a direction to move or a move N or go N
	auto verb = _parser->getVerb() == "move" || _parser->getVerb() == "go " ? _parser->getNoun() : _parser->getVerb();

	_commandResult = _player->Move(verb) ? _player->getCurrentRoom()->getLongDescription() : "There is no exit " + verb;

	cout << endl << _commandResult << endl;

}