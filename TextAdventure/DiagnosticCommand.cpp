/*
	File:				DiagnosticCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			1-26-2018
	Last Modified:		1-26-2018
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the DiagnosticCommand class

*/

#include "stdafx.h"

#include "DiagnosticCommand.h"

DiagnosticCommand::DiagnosticCommand()
	
{
}

DiagnosticCommand::DiagnosticCommand(string command)
	: CommandInterface(command)
{
}

DiagnosticCommand::DiagnosticCommand(string command, Player * player)
	: CommandInterface(command, player)
{
}

DiagnosticCommand::DiagnosticCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

DiagnosticCommand::~DiagnosticCommand()
{
}

void DiagnosticCommand::process()
{
	cout << "Player stats" << NEWLINE
		<< "Health: " << _player->getHitPoints() << "\\" << _player->getCurrentHitPoints() << NEWLINE
		<< "Score: " << _player->getScore() << endl;
}
