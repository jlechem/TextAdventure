/*
	ExamineCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-8-2018

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

ExamineCommand::ExamineCommand(string command,Player* player)
	:CommandInterface(command,player)
{
}

ExamineCommand::ExamineCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
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

	if (_parser->getNoun().empty())
	{
		_commandResult = "Examine what?";
	}
	else
	{
		string searchWord = examineItem(_parser->getNoun());
		_commandResult = searchWord.empty() ? "You don't have the " + _parser->getNoun() : searchWord;
	}

	cout << endl << _commandResult << endl;

}