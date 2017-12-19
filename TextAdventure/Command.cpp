#pragma once

#include "stdafx.h"
#include "Command.h"

Command::Command()
{
	_player = make_shared<Player>();
	loadActions();
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

/*
	Set the specified player into the command.
*/
void Command::setPlayer(shared_ptr<Player> player)
{
	_player = player;
}

void Command::process()
{	
	_commandResult.clear();

	// no text was entered
	if (_commands.size() == 0)
	{		
		_commandResult = "What do you want to do?";
	}
	// whatever was entered, the first thing has to be a valid verb/command
	else if ( !isValid(_commands[0]) )
	{
		_commandResult = "I don't know how to " + _commands[0];
	}
	else
	{
		string command = _commands[0];
		
		switch (_commands.size())
		{
			case 1:
				// if we have a look command then print the room
				if (isLookCommand(command))
				{
					setRoomDescription();
				}
				// if we have a 'fun' command print the result
				else if (isFunCommand(command))
				{
					_commandResult = _funCommands[command];
				}
				// if we have a move command then try and move
				else if (isMoveCommand(command))
				{
					_player->Move(command) ? setRoomDescription() : setInvalidMove(command);
				}
				else if (isActionCommand(command))
				{
					_commandResult = command + " what?";
				}
				else if (isExitCommand(command))
				{
					// TODO: add game option prompts before we exit
					exit(0);
				}
				else if (isClearCommand(command))
				{
					system("cls");
					setRoomDescription();
				}
				else if (isInventoryCommand(command))
				{
					_player->printInventory();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 2:
				// handle take and drop commands
				if (isTakeCommand(command))
				{
					takeItem();
				}
				else if (isDropCommand(command))
				{
					dropItem();
				}
				else if (isKillCommand(command))
				{
					// TODO: handle fighting
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 3:
				// handle take and drop commands
				if (isTakeCommand(command))
				{
					takeItem();
				}
				else if (isDropCommand(command))
				{
					dropItem();
				}
				else if (isKillCommand(command))
				{
					// TODO: handle fighting
				}
				else if (isLookCommand(command))
				{
					// TODO: implement complex Look
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 4:
				// look at X T Z
				if (isLookCommand(command))
				{
					// TODO: implement complex Look
				}
				else if (isTakeCommand(command))
				{
					takeItem();
				}
				else if (isDropCommand(command))
				{
					dropItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			default:
				if (isTakeCommand(command))
				{
					takeItem();
				}
				else if (isDropCommand(command))
				{
					dropItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;
		}
	}

	printResult();

}

void Command::printResult()
{
	cout << endl << _commandResult << endl;
}

/*
	Gets our list of verbs.
*/
vector<string>& Command::getVerbs()
{
	return _validActions;
}

/*
	Parses our command
*/
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

void Command::takeItem() 
{
	// this means they typed 'take the' and nothing else
	if (_commands.size() == 2 && 
		_commands[1] == "the" )
	{
		_commandResult = "take what?";
	}
	// take X Z
	// or take the X Y Z
	else
	{
		// skip 'the' word if needed
		auto startIndex = _commands[1] == "the" ? 2 : 1;

		// we need to concat words based on spaces
		string item = "";

		for (auto i = startIndex; i < _commands.size(); i++)
		{
			item += _commands[i] + " ";
		}

		// clear the last space at the end
		item.erase(item.end() - 1);

		// try and add this item from the room to the player
		_commandResult = _player->addItem(item) ? "You pick up the " + item : "You don't see a " + item + " here";
		
	}	
}

void Command::dropItem()
{
	// this means they typed 'take the' and nothing else
	if (_commands.size() == 2 &&
		_commands[1] == "the")
	{
		_commandResult = "drop what?";
	}
	// take X Z
	// or take the X Y Z
	else
	{
		// skip 'the' word if needed
		auto startIndex = _commands[1] == "the" ? 2 : 1;

		// we need to concat words based on spaces
		string item = "";

		for (auto i = startIndex; i < _commands.size(); i++)
		{
			item += _commands[i] + " ";
		}

		// clear the last space at the end
		item.erase(item.end() - 1);

		// try and add this item from the room to the player
		_commandResult = _player->dropItem(item) ? "You drop the " + item : "You don't have a " + item;

	}
}

/*
	Loads all of our valid actions into a list.
*/
void Command::loadActions()
{
	// TODO: load the actions from the config file
	_funCommands["jump"] = "You jump up and down";
	_funCommands["sleep"] = "You lie down and sleep, refreshing!";
	_funCommands["rest"] = "You rest for a minute";
	_funCommands["hum"] = "You hum a ditty, it makes the work go by faster";
	_funCommands["sing"] = "You sing that song you like, but the key seems to be off.....";
}

/*
	Checks the action against our list of valid actions to determine if it's valid or not.
*/
bool Command::isValid(string action)
{
	auto command = find(_validActions.begin(), _validActions.end(), action);

	return command != _validActions.end();
}

/*
	Takes the current players current room and uses it to build a description of the room
	the player is in
*/
void Command::setRoomDescription()
{
	_commandResult = _player->getCurrentRoom()->getDescription();
	_commandResult += "\nYou see the following exists: " + _player->getCurrentRoom()->getExitsString();
	_commandResult += "\nYou see the following items: " + _player->getCurrentRoom()->getItems();
}

/*
	Sets our command result to an invalid direction movement.
*/
void Command::setInvalidMove(string direction)
{
	_commandResult = "There is no exit " + direction;
}

/*
	This function checks if we have a kill command (kill or fight)
*/
bool Command::isKillCommand(string verb)
{
	return verb == "kill" || verb == "fight";
}

/*
	This function checks if the command is in our 'fun' command list
*/
bool Command::isFunCommand(string verb)
{
	auto result = _funCommands.find(verb);
	
	return result != _funCommands.end();
}

/*
	This function determines if a command requires a second part, ie kill X, drop X, take X
*/
bool Command::isActionCommand(string verb)
{
	return	isKillCommand(verb) ||
			isDropCommand(verb) ||
			isTakeCommand(verb);
}

/*
	This function checks if we have a clear screen command
*/
bool Command::isClearCommand(string command)
{
	return command == "cls" || command == "clear";
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