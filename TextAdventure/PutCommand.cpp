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
	// PUT ITEM IN ITEM
	// PUT THE ITEM IN THE ITEM
	auto tempWord = _parser->getVerb() + _parser->getArticleOne() + _parser->getArticleTwo() + _parser->getNoun();

	// erase THE and IN
	// now we should have ITEM ITEM
	tempWord.erase(std::remove(tempWord.begin(), tempWord.end(), 'the'), tempWord.end());
	tempWord.erase(std::remove(tempWord.begin(), tempWord.end(), 'in'), tempWord.end());

	// split based on first space we find
	char delim = ' ';
	stringstream ss(tempWord);
	string temp;

	vector<string>* tempVector = new vector<string>(2);

	while (std::getline(ss, temp, delim))
	{
		// trim before we put into the vector
		tempVector->push_back(temp);
	}

	item = (*tempVector)[0];
	container = (*tempVector)[1];

	delete tempVector;

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

		// get the item and container from the noun
		split(item, container);

		bool isFromPlayer = true;

		// get the item and container from the player or the room
		auto itemPointer = _player->findItem(item);

		if (!itemPointer)
		{
			itemPointer = _player->getCurrentRoom()->findItem(item);
			isFromPlayer = false;
		}

		auto containerPointer = _player->findItem(container);

		if (!containerPointer)
		{
			containerPointer = _player->getCurrentRoom()->findItem(item);
			isFromPlayer = false;
		}

		// we found both items
		if (itemPointer && containerPointer)
		{
			// first check if the container can even take items
			if (containerPointer->getCanAddItem())
			{
				// check that the container is open
				if (containerPointer->getIsOpen())
				{
					// finally put the item in there

				}
				else
				{
					_commandResult = container + ": Nice try, it isn't open";
				}
			}
			else
			{
				_commandResult = container + ": Nice try, can't put anything in here";
			}

			// always put the container back where we found it
			if (isFromPlayer)
			{
				_player->addItem(containerPointer->getName());
			}
			else
			{
				_player->getCurrentRoom()->addItem(std::move(containerPointer));
			}
		}
		// only found an item
		else if (itemPointer && !containerPointer)
		{
			_commandResult = "There's no " + container + " here";

			// always put the item back where we found it
			if (isFromPlayer)
			{
				_player->getCurrentRoom()->addItem(std::move(itemPointer));
				_player->addItem(item);
			}
			else
			{
				_player->getCurrentRoom()->addItem(std::move(itemPointer));
			}
		}
		// only found a container
		else if (!itemPointer && containerPointer)
		{
			_commandResult = "There's no " + item + " here";

			// always put the container back where we found it
			if (isFromPlayer)
			{
				_player->getCurrentRoom()->addItem(std::move(containerPointer));
				_player->addItem(container);
			}
			else
			{
				_player->getCurrentRoom()->addItem(std::move(itemPointer));
				_player->addItem(item);

				_player->getCurrentRoom()->addItem(std::move(containerPointer));
			}
		}
		// we didn't find anything
		// no pointers so no need to put anything back
		else
		{
			_commandResult = "There's no " + container + " or " + item + " here";
		}

		cout << endl << _commandResult << endl;

	}
}