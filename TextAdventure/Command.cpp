#include "stdafx.h"
#include "Command.h"


Command::Command()
{
	_verbs = make_unique<vector<string>>();
}

Command::Command(string command): Command()
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

unique_ptr<vector<string>>& Command::getVerbs()
{
	return _verbs;
}

bool Command::IsValid()
{


	return _isValid;
}

void Command::parseCommand()
{
	// tokenize the command based on spaces
}

void Command::calculateIsValid()
{
	if (_command.size() == 0)
	{
		_isValid = false;
	}
	else
	{

	}
	
	_isValid = false;

}