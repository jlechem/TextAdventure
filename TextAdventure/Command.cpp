#include "stdafx.h"
#include "Command.h"


Command::Command()
{
}

Command::Command(string command)
{
	_command = command;
	parseCommand();
	calculateIsValid();	
}


Command::~Command()
{
}

void Command::setCommand(string command)
{
	_command = command;
	parseCommand();
	calculateIsValid();
}

string Command::getCommand()
{
	return _command;
}

bool Command::IsValid()
{
	return _isValid;
}

void Command::parseCommand()
{
}

void Command::calculateIsValid()
{
	_isValid = false;
}
