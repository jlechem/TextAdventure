#include "stdafx.h"
#include "JumpCommand.h"


JumpCommand::JumpCommand()
	: CommandInterface()
{
	_isValid = true;
}

JumpCommand::JumpCommand(string command, shared_ptr<Player> player)
	: CommandInterface(command, player)
{
	_isValid = true;
}


JumpCommand::~JumpCommand()
{
}

void JumpCommand::process()
{
	cout << endl << "You jump up and down" << endl;
}

void JumpCommand::calculateValidity()
{
	// this command is always true
}