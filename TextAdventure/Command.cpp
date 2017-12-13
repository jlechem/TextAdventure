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
}


Command::~Command()
{
}

void Command::setCommand(string command)
{
	_command = command;
	parseCommand();
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
	char delim = ' ';
	stringstream ss(_command);
	string item;
	vector<string> tokens;

	while (std::getline(ss, item, delim)) 
	{
		tokens.push_back(item);
	}

	calculateIsValid(tokens);

}

void Command::calculateIsValid(vector<string> tokens)
{
	if (_command.size() == 0)
	{
		_isValid = false;
	}
	else
	{
		// look at the size, we can only handle certain combos of text
		// 1, 2, or 3
		if (tokens.size() != 1 ||
			tokens.size() != 2 ||
			tokens.size() != 3)
		{
			_isValid = false;
		}
		else
		{
			// based on the number of tokens we need to validate our command
		}
	}
	
	_isValid = false;

}