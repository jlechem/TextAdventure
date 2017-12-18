#pragma once

#include "stdafx.h"
#include "Command.h"

Command::Command()
{
	_verbs = make_unique<vector<string>>();
	_actionType = ActionType::InvalidAction;
	_player = make_shared<Player>();
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

string Command::getAction()
{
	return _action;
}

string Command::getNoun()
{
	return _noun;
}

string Command::getModifier()
{
	return _modifier;
}

string Command::getCommandResult()
{
	return _commandResult;
}

ActionType Command::getActionType()
{
	return _actionType;
}

void Command::setPlayer(shared_ptr<Player> player)
{
	_player = player;
}

unique_ptr<vector<string>>& Command::getVerbs()
{
	return _verbs;
}

void Command::Process()
{
	// TODO: Process the command entered in before
}

void Command::PrintResult()
{
	cout << endl << _commandResult << endl;
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
	
	_action = "";
	_noun = "";
	_modifier = "";

	// look at the size, we can only handle certain combos of text
	// 1, 2, or 3
	if (tokens.size() == 1 ||
		tokens.size() == 2 ||
		tokens.size() == 3 )
	{
		_action = tokens[0];

		// based on the number of tokens we need to validate our command
		switch (tokens.size())
		{
		case 1:
			calculateActionType(_action);
			break;

		case 2:
			_noun = tokens[1];
			calculateActionType(_action);
			break;

		case 3:
			_modifier = tokens[1];
			_noun = tokens[2];
			calculateActionType(_action);
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
	else if (isExitCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Quit;
	}
	else if (isTakeCommand(verb))
	{
		_isValid = true;
		_actionType = ActionType::Take;
	}
	else if (isActionCommand(verb))
	{
		_isValid = true;
		calculateActionResult(verb);
		_actionType = ActionType::Action;
	}
	else
	{
		_isValid = false;
		_actionType = ActionType::InvalidAction;
	}
}

void Command::calculateActionResult(string verb)
{
	if (verb == "jump")
	{
		_commandResult = "You jump up and down";
	}
	else if (verb == "sleep")
	{
		_commandResult = "You lie down and sleep for a while, refreshing!";
	}
	else if (verb == "rest")
	{
		_commandResult = "You rest for a minute";
	}
	else if (verb == "hum")
	{
		_commandResult = "You hum a little ditty, it seems to make the work go by faster.";
	}
	else if (verb == "sing")
	{
		_commandResult = "You sing a song, but the key seems to be off....";
	}

}

bool Command::isActionCommand(string verb)
{
	return verb == "jump" || verb == "sleep" || verb == "rest" || verb == "hum" || verb == "sing";
}