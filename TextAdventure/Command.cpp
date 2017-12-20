/*
	Command.cpp
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-20-2017
	Notes: Implementation of the command class
*/

#pragma once

#include "stdafx.h"
#include "Command.h"

/// <summary>
/// Initializes a new instance of the <see cref="Command"/> class.
/// </summary>
Command::Command()
{
	_player = make_shared<Player>();
	loadActions();
}

/// <summary>
/// Initializes a new instance of the <see cref="Command"/> class.
/// </summary>
/// <param name="command">The command.</param>
Command::Command(string command) : Command()
{
	_command = command;
	parseCommand();
}

/// <summary>
/// Finalizes an instance of the <see cref="Command"/> class.
/// </summary>
Command::~Command()
{
}

/// <summary>
/// Sets the command.
/// </summary>
/// <param name="command">The command.</param>
void Command::setCommand(string command)
{
	_command = command;
	parseCommand();
}

/// <summary>
/// Gets the command.
/// </summary>
/// <returns></returns>
string Command::getCommand()
{
	return _command;
}

/// <summary>
/// Gets the command result.
/// </summary>
/// <returns></returns>
string Command::getCommandResult()
{
	return _commandResult;
}

/// <summary>
/// Sets the player.
/// </summary>
/// <param name="player">The player.</param>
void Command::setPlayer(shared_ptr<Player> player)
{
	_player = player;
}

/// <summary>
/// Processes this instance.
/// </summary>
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
					lookAtItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 3:
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
					lookAtItem();
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

/// <summary>
/// Prints the result.
/// </summary>
void Command::printResult()
{
	cout << endl << _commandResult << endl;
}

/// <summary>
/// Gets the verbs.
/// </summary>
/// <returns></returns>
vector<string>& Command::getVerbs()
{
	return _validActions;
}

/// <summary>
/// Parses the command.
/// </summary>
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

/// <summary>
/// Takes the item.
/// </summary>
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

/// <summary>
/// Drops the item.
/// </summary>
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

void Command::lookAtItem()
{
	// TODO: implement complex and simple look results
}

/// <summary>
/// Loads the actions.
/// </summary>
void Command::loadActions()
{
	// TODO: load the actions from the config file
	_funCommands["jump"] = "You jump up and down";
	_funCommands["sleep"] = "You lie down and sleep, refreshing!";
	_funCommands["rest"] = "You rest for a minute";
	_funCommands["hum"] = "You hum a ditty, it makes the work go by faster";
	_funCommands["sing"] = "You sing that song you like, but the key seems to be off.....";
}

/// <summary>
/// Determines whether the specified action is valid.
/// </summary>
/// <param name="action">The action.</param>
/// <returns>
///   <c>true</c> if the specified action is valid; otherwise, <c>false</c>.
/// </returns>
bool Command::isValid(string action)
{
	auto command = find(_validActions.begin(), _validActions.end(), action);

	return command != _validActions.end();
}

/// <summary>
/// Sets the room description.
/// </summary>
void Command::setRoomDescription()
{
	_commandResult = _player->getCurrentRoom()->getDescription();
	_commandResult += "\nYou see the following exists: " + _player->getCurrentRoom()->getExitsString();
	_commandResult += "\nYou see the following items: " + _player->getCurrentRoom()->getItems();
}

/// <summary>
/// Sets the invalid move.
/// </summary>
/// <param name="direction">The direction.</param>
void Command::setInvalidMove(string direction)
{
	_commandResult = "There is no exit " + direction;
}

/// <summary>
/// Determines whether [is kill command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is kill command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isKillCommand(string verb)
{
	return verb == "kill" || verb == "fight";
}

/// <summary>
/// Determines whether [is fun command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is fun command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isFunCommand(string verb)
{
	auto result = _funCommands.find(verb);
	
	return result != _funCommands.end();
}

/// <summary>
/// Determines whether [is action command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is action command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isActionCommand(string verb)
{
	return	isKillCommand(verb) ||
			isDropCommand(verb) ||
			isTakeCommand(verb);
}

/// <summary>
/// Determines whether [is clear command] [the specified command].
/// </summary>
/// <param name="command">The command.</param>
/// <returns>
///   <c>true</c> if [is clear command] [the specified command]; otherwise, <c>false</c>.
/// </returns>
bool Command::isClearCommand(string command)
{
	return command == "cls" || command == "clear";
}

/// <summary>
/// Determines whether [is move command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is move command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
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

/// <summary>
/// Determines whether [is take command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is take command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isTakeCommand(string verb)
{
	return verb == "take";
}

/// <summary>
/// Determines whether [is look command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is look command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isLookCommand(string verb)
{
	return verb == "look" || verb == "l" || verb == "examine";
}

/// <summary>
/// Determines whether [is drop command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is drop command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isDropCommand(string verb)
{
	return verb == "drop";
}

/// <summary>
/// Determines whether [is item command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is item command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isItemCommand(string verb)
{
	return false;
}

/// <summary>
/// Determines whether [is inventory command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is inventory command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isInventoryCommand(string verb)
{
	return	verb == "i" ||
		verb == "inventory";
}

/// <summary>
/// Determines whether [is save command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is save command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isSaveCommand(string verb)
{
	return verb == "save";
}

/// <summary>
/// Determines whether [is exit command] [the specified verb].
/// </summary>
/// <param name="verb">The verb.</param>
/// <returns>
///   <c>true</c> if [is exit command] [the specified verb]; otherwise, <c>false</c>.
/// </returns>
bool Command::isExitCommand(string verb)
{
	return	verb == "exit" ||
		verb == "quit" ||
		verb == "q";
}