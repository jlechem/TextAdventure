#pragma once

#include "stdafx.h"
#include "Command.h"

Command::Command()
{
	_verbs = make_unique<vector<string>>();
	_actionType = ActionType::InvalidAction;
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

ActionType Command::getActionType()
{
	return _actionType;
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
	_isValid = false;

	// look at the size, we can only handle certain combos of text
	// 1, 2, or 3
	if (tokens.size() == 1 ||
		tokens.size() == 2 ||
		tokens.size() == 3 )
	{
		// based on the number of tokens we need to validate our command
		switch (tokens.size())
		{
		case 1:
			calculateActionType(tokens[0]);
			break;

		case 2:
			break;

		case 3:
			break;

		default:
			break;
		}
	}
}

bool Command::isMoveCommand(string verb)
{
	return
		verb == "north" ||
		verb == "south" ||
		verb == "east" ||
		verb == "west" ||
		verb == "n" ||
		verb == "e" ||
		verb == "s" ||
		verb == "w" ||
		verb == "northeast" ||
		verb == "northwest" ||
		verb == "southeast" ||
		verb == "southwest" ||
		verb == "ne" ||
		verb == "nw" ||
		verb == "se" ||
		verb == "sw";
}

bool Command::isTakeCommand(string verb)
{
	return verb == "take";
}

bool Command::isLookCommand(string verb)
{
	return verb == "look" || verb == "l";
}

bool Command::isDropCommand(string verb)
{
	return verb == "drop";
}

bool Command::isItemCommand(string verb)
{
	return false;
}

bool Command::isInventoryCommand(string verb)
{
	return	verb == "i" ||
		verb == "inventory";
}

bool Command::isSaveCommand(string verb)
{
	return verb == "save";
}

bool Command::isExitCommand(string verb)
{
	return	verb == "exit" ||
		verb == "quit" ||
		verb == "q";
}

void Command::calculateActionType(string verb)
{
	// single verb comamnds can be
	// movement, N S E W, etc
	// look (room)
	// save
	// quit
	// inventory, i
	if (isMoveCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Movement;
	}
	else if (isLookCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Look;
	}
	else if (isSaveCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Save;
	}
	else if (isInventoryCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Inventory;
	}
	else
	{
		_isValid = false;
		_actionType = ActionType::InvalidAction;
	}
}