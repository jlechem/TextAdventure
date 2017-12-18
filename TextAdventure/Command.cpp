#pragma once

#include "stdafx.h"
#include "Command.h"

Command::Command()
{
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

string Command::getCommandResult()
{
	return _commandResult;
}

void Command::setPlayer(shared_ptr<Player> player)
{
	_player = player;
}


void Command::process()
{	
	// no text was entered
	if (_commands.size() == 0)
	{		
		_commandResult = "What do you want to do?";
	}
	else if ( !isValid(_commands[0]) )
	{
		_commandResult = "I don't know how to " + _commands[0];
	}
	else
	{
		// TODO: Process the command entered in before
		// check for fun things, ie jump, hum, etc
		switch (_commands.size())
		{
			case 1:

				// if we have a look command then print the room

				// if we have a 'fun' command print the result

				// if we have a move command then move

				break;

			case 2:
				break;

			case 3:
				break;

			default:
				break;
		}
	}

	printResult();

}

void Command::printResult()
{
	cout << endl << _commandResult << endl;
}

vector<string>& Command::getVerbs()
{
	return _validActions;
}

void Command::parseCommand()
{
	// tokenize the command based on spaces
	char delim = ' ';
	stringstream ss(_command);
	string item;
	
	_commands.clear();

	while (std::getline(ss, item, delim)) 
	{
		transform(item.begin(), item.end(), item.begin(), tolower);
		_commands.push_back(item);
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

void Command::calculateActionResult(string verb)
{
}

void Command::loadActions()
{
	// TODO: load the actions from the config file
	_funCommands["jump"] = "You jump up and down";
	_funCommands["sleep"] = "You lie down and sleep, refreshing!";
	_funCommands["rest"] = "You rest for a minute";
	_funCommands["hum"] = "You hum a ditty, it makes the work go by faster";
	_funCommands["sing"] = "You sing that song you like, but the key seems to be off.....";
}

bool Command::isValid(string action)
{
	bool result = false;

	vector<string>::iterator it;

	for (it = _validActions.begin(); it != _validActions.end(); ++it)
	{
		if ((*it) == action)
		{
			result = true;
			break;
		}
	}

	return result;

}

bool Command::isActionCommand(string verb)
{
	return verb == "jump" || verb == "sleep" || verb == "rest" || verb == "hum" || verb == "sing";
}