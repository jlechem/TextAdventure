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
				if (Utilities::isLookCommand(command))
				{
					setRoomDescription();
				}
				// if we have a 'fun' command print the result
				else if (Utilities::isFunCommand(command))
				{
					_commandResult = _funCommands[command];
				}
				// if we have a move command then try and move
				else if (Utilities::isMoveCommand(command))
				{
					_player->Move(command) ? setRoomDescription() : setInvalidMove(command);
				}
				else if (Utilities::isActionCommand(command) || Utilities::isExamineCommand(command))
				{
					_commandResult = command + " what?";
				}
				else if (Utilities::isExitCommand(command))
				{
					// TODO: add game option prompts before we exit
					exit(0);
				}
				else if (Utilities::isClearCommand(command))
				{
					system("cls");
					setRoomDescription();
				}
				else if (Utilities::isInventoryCommand(command))
				{
					_player->printInventory();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 2:
				if (Utilities::isTakeCommand(command))
				{
					takeItem();
				}
				else if (Utilities::isDropCommand(command))
				{
					dropItem();
				}
				else if (Utilities::isKillCommand(command))
				{
					// TODO: handle fighting
				}
				else if (Utilities::isLookCommand(command))
				{
					lookAtItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 3:
				if (Utilities::isTakeCommand(command))
				{
					takeItem();
				}
				else if (Utilities::isDropCommand(command))
				{
					dropItem();
				}
				else if (Utilities::isKillCommand(command))
				{
					// TODO: handle fighting
				}
				else if (Utilities::isLookCommand(command))
				{
					lookAtItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			case 4:
				if (Utilities::isLookCommand(command))
				{
					lookAtItem();
				}
				else if (Utilities::isTakeCommand(command))
				{
					takeItem();
				}
				else if (Utilities::isDropCommand(command))
				{
					dropItem();
				}
				else
				{
					_commandResult = "I don't know how to " + _command;
				}

				break;

			default:
				_commandResult = "I don't know how to " + _command;

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
		Utilities::toLower(item);
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
	if (_commands.size() == 2 &&
		_commands[1] == "the")
	{
		_commandResult = "take what?";
	}
	else if (_commands.size() == 2 &&
		_commands[1] == "all")
	{
		_commandResult = _player->takeAllItems();
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

void Command::examinteItem()
{
	// this means they typed 'look at' || 'looked at the' and nothing else
	if ((_commands.size() == 2 && _commands[1] == "at") ||
		(_commands.size() == 3 && _commands[1] == "at" && _commands[2] == "the"))
	{
		_commandResult = "Look at what?";
	}
	else
	{
		int startIndex = 0;

		switch (_commands.size())
		{
		case 2:
			startIndex = 1;
			break;

		case 3:
			startIndex = _commands[1] == "at" ? 2 : 1;
			break;

		case 4:
			startIndex = _commands[1] == "at" && _commands[2] == "the" ? 3 : 2;
			break;

		default:
			break;

		}

		// we need to concat words based on spaces
		string item = "";

		for (auto i = startIndex; i < _commands.size(); i++)
		{
			item += _commands[i] + " ";
		}

		// remove the last space
		item.erase(item.end() - 1);

		// see if the room has this item
		auto foundItem = _player->getCurrentRoom()->findItemDescription(item);

		_commandResult = foundItem.size() == 0 ? "You don't see a " + item + " here" : "You see " + foundItem;

	}
}

/// <summary>
/// Looks at item.
/// </summary>
void Command::lookAtItem()
{
	// this means they typed 'look at' || 'looked at the' and nothing else
	if ( (_commands.size() == 2 && _commands[1] == "at" ) || 
		 (_commands.size() == 3 && _commands[1] == "at" && _commands[2] == "the" ) )
	{
		_commandResult = "Look at what?";
	}
	else
	{
		int startIndex = 0;

		switch (_commands.size())
		{
		case 2:
			startIndex = 1;
			break;

		case 3:
			startIndex = _commands[1] == "at" ? 2 : 1;
			break;

		case 4:
			startIndex = _commands[1] == "at" && _commands[2] == "the" ? 3 : 2;
			break;

		default:
			break;

		}

		// we need to concat words based on spaces
		string item = "";

		for (auto i = startIndex; i < _commands.size(); i++)
		{
			item += _commands[i] + " ";
		}

		// remove the last space
		item.erase(item.end() - 1);

		// see if the room has this item
		auto foundItem = _player->getCurrentRoom()->findItemDescription(item);

		_commandResult = foundItem.size() == 0 ? "You don't see a " + item + " here" : "You see " + foundItem;
		
	}
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
/// Sets the room description.
/// </summary>
void Command::setRoomDescription()
{
	_commandResult = _player->getCurrentRoom()->getDescription();

	if (_player->getCurrentRoom()->getExitsString().size() > 0)
	{
		_commandResult += "\nYou see the following exists: " + _player->getCurrentRoom()->getExitsString();
	}

	if (_player->getCurrentRoom()->getItemsString().size() > 0)
	{
		_commandResult += "\nYou see the following items: " + _player->getCurrentRoom()->getItemsString();
	}
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