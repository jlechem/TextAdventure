/*
	File:				PutCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		1-10-2018
	Last Modified By:	Justin LeCheminant

	Notes:				Implementation of the PutCommand class.

*/

#include "stdafx.h"

#include "PutCommand.h"

PutCommand::PutCommand()
	: CommandInterface()
{
}

PutCommand::PutCommand(string command)
	: CommandInterface(command)
{
}

PutCommand::PutCommand(string command,Player* player)
	: CommandInterface(command,player) 
{
}

PutCommand::PutCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

PutCommand::~PutCommand()
{
}

void PutCommand::split(string& item, string& container)
{
	// ITEM IN ITEM
	// THE ITEM IN THE ITEM
	// ITEM IN THE ITEM
	// THE ITEM IN ITEM
	auto tempWord = _parser->getNoun();

	// erase THE
	// now we should have X Y Z (LONG ITEM NOUN) IN  X Y Z (LONG ITEM NOUN)
	regex pattern(" the ");
	tempWord = regex_replace(tempWord, pattern, " ");
	pattern.assign("the ");
	tempWord = regex_replace(tempWord, pattern, " ");

	// find the first instance of 'in'
	auto location = tempWord.find(" in ");

	// based on the index of the 'in' we split the sentence into item and container
	if (location != string::npos)
	{
		item = tempWord.substr(0, location);
		container = tempWord.substr(location + 3, tempWord.size());

		Utilities::trim(item);
		Utilities::trim(container);
	}
	else
	{
		// we don't have an in so the item is first???
		item = tempWord;
	}
}

void PutCommand::process()
{
	// empty PUT
	if (_parser->getNoun().empty())
	{
		_commandResult = "Put what in what?";
	}
	else
	{
		string item = "", container = "";

		// get the item and container from the Parser's noun
		split(item, container);

		// do some validation
		if (item.empty() && !container.empty())
		{
			_commandResult = "Put what in the " + container;
		}
		else if (!item.empty() && container.empty())
		{
			_commandResult = "Put " + item + " in what?";
		}
		else if (item.empty() && container.empty())
		{
			_commandResult = "Put what in what";
		}
		else if (item == container)
		{
			_commandResult = "You can't put the " + item + " in itself";
		}
		else
		{
			auto isPlayerItem = true;
			auto isPlayerContainer = true;

			// get the item and container from the player or the room
			auto itemPointer = _player->findItem(item);

			if (!itemPointer)
			{
				itemPointer = _player->getCurrentRoom()->findItem(item);
				isPlayerItem = false;
			}

			auto containerPointer = _player->findItem(container);
			
			if (!containerPointer)
			{
				containerPointer = _player->getCurrentRoom()->findItem(container);
				isPlayerContainer = false;
			}

			// we found both items
			if (itemPointer && containerPointer)
			{
				if (containerPointer->getCanAddItem())
				{
					if (containerPointer->getIsOpen())
					{
						containerPointer->addItem(std::move(itemPointer));
						_commandResult = item + ": Placed into - " + container;
					}
					else
					{
						_commandResult = container + ": Nice try, it isn't open";
					}
				}
				else
				{
					_commandResult = container + ": Nice try, you can't put anything in that";
				}
			}
			// only found an item
			else if (itemPointer && !containerPointer)
			{
				_commandResult = "There's no " + container + " here";
			}
			// only found a container
			else if (!itemPointer && containerPointer)
			{
				_commandResult = "There's no " + item + " here";
			}
			// we didn't find anything
			else
			{
				_commandResult = "There's no " + container + " or " + item + " here";
			}

			// finally we need to do some pointer stuff and move items back where they 
			if (itemPointer)
			{
				// if we have an item pointer it means an error happened and the item never got moved
				if (isPlayerItem)
				{
					_player->addItem(std::move(itemPointer));
				}
				else
				{
					_player->getCurrentRoom()->addItem(std::move(itemPointer));
				}
			}
			
			// if we found a container it always goes back no matter what
			if (containerPointer)
			{
				if (isPlayerContainer)
				{
					_player->addItem(std::move(containerPointer));
				}
				else
				{
					_player->getCurrentRoom()->addItem(std::move(containerPointer));
				}
			}
		}

		cout << endl << _commandResult << endl;

	}
}