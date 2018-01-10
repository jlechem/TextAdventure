/*
	File:				PutCommand.cpp
	Created By:			Justin LeCheminant
	Created On:			12-27-2017
	Last Modified:		1-9-2018
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

void PutCommand::process()
{
	// TODO: implement process for PuCommand

	// empty PUT
	if (_parser->getNoun().empty())
	{
		_commandResult = "Put what?";
	}
	else
	{
		// PUT ITEM IN ITEM
		// PUT THE ITEM IN THE ITEM
		auto tempWord = _parser->getVerb() + _parser->getArticleOne() + _parser->getArticleTwo() + _parser->getNoun();

		// erase THE and IN
		// TODO: trim any leading/trailing whitespace
		// now we should have ITEM ITEM
		tempWord.erase(std::remove(tempWord.begin(), tempWord.end(), 'the'), tempWord.end());
		tempWord.erase(std::remove(tempWord.begin(), tempWord.end(), 'in'), tempWord.end());

		// TODO: split based on first space we find
		string item = "";
		string container = "";

		bool personContainer = false;

		// find the first item either in the room or on the player
		// find the second item either in the room or on the player
		auto itemPointer = _player->getCurrentRoom()->findItem(item);
		
		if (!itemPointer)
		{
			itemPointer = _player->dropItem(item,false);
		}

		auto containerPointer = _player->getCurrentRoom()->findItem(container);

		if (!containerPointer)
		{
			containerPointer = _player->dropItem(item, false);
			personContainer = true;
		}

		// only continue if we found both items
		if (containerPointer && itemPointer)
		{
			// check if the container can even hold anything
			if (containerPointer->getCanAddItem())
			{
				// if it can hold something check if it's open
				if (containerPointer->getIsOpen())
				{
					// check if the container if full
					if (!containerPointer->getIsFull())
					{
						// TODO: validate the item going in can fit into the container

						// ok the container is open, not full, lets put the new item in it
						containerPointer->addItem(std::move(itemPointer));

						// now put the container back where it came from, this could be a person or room
						if (personContainer)
						{
							_player->addItem(std::move(containerPointer));
						}
						else
						{
							_player->getCurrentRoom()->addItem(std::move(containerPointer));
						}

						// pheew made it through all the validations
						_commandResult = "You put the " + item + " in the " + container;

					}
					else
					{
						_commandResult = "Sorry " + container + " is full";
					}
				}
				else
				{
					_commandResult = container + " isn't open";
				}
			}
			else
			{
				_commandResult = container + " can't hold anything";
			}
		}
		else
		{
			// setting formatting for error messages
			if (!itemPointer && !containerPointer)
			{
				_commandResult = "There's no " + item + " or " + container + " here";
			}
			else if (!itemPointer && containerPointer)
			{
				_commandResult = "There's no " + item + " here";
			}
			else
			{
				_commandResult = "There's no "  + container + " here";
			}
		}
	}

	cout << endl << _commandResult << endl;

}