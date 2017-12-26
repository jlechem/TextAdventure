/*
	ExamineCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-21-2017

	Notes: Implemenation of the ExamineCommand class.

*/

#include "stdafx.h"

#include "ExamineCommand.h"

ExamineCommand::ExamineCommand()
	: CommandInterface()
{
}

ExamineCommand::ExamineCommand(string command) 
	: CommandInterface(command)
{
}

ExamineCommand::ExamineCommand(string command, shared_ptr<Player> player)
	:CommandInterface(command,player)
{
}

ExamineCommand::~ExamineCommand()
{
}

string ExamineCommand::examineItem(string name)
{
	auto items = _player->getInventory();

	string result = "";

	vector<unique_ptr<Item>>::iterator it;

	// loop through the items
	for (it = items->begin(); it != items->end(); ++it)
	{
		// check our alternate names to see if we have this item
		auto foundItem = find((*it)->getAlterateNames().begin(), (*it)->getAlterateNames().end(), name);

		if (foundItem != (*it)->getAlterateNames().end())
		{
			result = (*it)->getDescription();
			break;
		}
	}

	return result;

}

void ExamineCommand::process()
{
	calculateValidity();

	if (_isValid)
	{
		string searchWord = "";

		switch (_commandWords.size())
		{
		case 1:
			// EXAMINE 
			_commandResult = "Examine what?";
			break;

		case 2:
			// EXAMINE X
			searchWord = examineItem(_commandWords[1]);
			_commandResult = searchWord.empty() ? "You don't have the " + _commandWords[1] : searchWord;

			break;

		default:
			// TODO: Implement complex examine
			break;
		}
	}
	else
	{
		_commandResult = "I don't know how to " + _command;
	}
	
	cout << endl << _commandResult << endl;

}

void ExamineCommand::calculateValidity()
{
	// word count should be between 1 and 3
	auto wordCount = _commandWords.size();

	_isValid = wordCount > 0 && wordCount < 4;

}