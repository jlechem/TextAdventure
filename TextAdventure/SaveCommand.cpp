/*
	SaveCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	12-29-2017

	Notes: Implemenation of the SaveCommand class.

*/

#include "stdafx.h"

#include "SaveCommand.h"

SaveCommand::SaveCommand()
	: CommandInterface()
{
	_isValid = true;
}

SaveCommand::SaveCommand(string command)
	: CommandInterface(command)
{
	_isValid = true;
}

SaveCommand::SaveCommand(string command,Player* player)
	: CommandInterface(command, player)
{
	_isValid = true;
}

SaveCommand::~SaveCommand()
{
}

void SaveCommand::process()
{
	string filename = "SAVE\\save.dat";

	// open file for output in binary truncating any existing data
	ofstream file(filename, ios::out | ios::trunc);

	// now write out all our items
	vector<unique_ptr<Item>>::iterator it;

	// the room id the player is in, followed by their score
	file << _player->getCurrentRoom()->getId() << " " << _player->getScore() << " ";

	for (it = _player->getInventory()->begin(); it != _player->getInventory()->end(); ++it)
	{
		file << (*it)->getId();

		if (it != _player->getInventory()->end() - 1)
		{
			file << " ";
		}
		else
		{
			file << endl;
		}
	}

	file.close();

	std::cout << "Saved" << endl;

}

void SaveCommand::calculateValidity()
{
}