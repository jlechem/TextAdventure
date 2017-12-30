#include "stdafx.h"
#include "HelpCommand.h"


HelpCommand::HelpCommand()
	: CommandInterface()
{
}

HelpCommand::HelpCommand(string command)
	: CommandInterface(command)
{
}

HelpCommand::HelpCommand(string command, Player* player)
	: CommandInterface(command,player) 
{
}

HelpCommand::~HelpCommand()
{
}

void HelpCommand::process()
{
}

void HelpCommand::calculateValidity()
{
}
