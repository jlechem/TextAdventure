/*
	File:			SaveCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			Implemenation of the SaveCommand class.

*/

#include "stdafx.h"

#include "SaveCommand.h"

SaveCommand::SaveCommand()
	: CommandInterface()
{
}

SaveCommand::SaveCommand(string command)
	: CommandInterface(command)
{
}

SaveCommand::SaveCommand(string command,Player* player)
	: CommandInterface(command, player)
{
}

SaveCommand::SaveCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command, player, parser)
{
}

SaveCommand::~SaveCommand()
{
}

void SaveCommand::process()
{
	string filename = "SAVE\\save.dat";

	// open file for output in binary truncating any existing data
	ofstream file(filename, ios::out | ios::binary | ios::trunc);

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

	// write out our room and item data

	// loop through the rooms
	for (auto i = 0; i < Rooms::getInstance().getRooms().size(); i++)
	{
		// get any items we might have in this room
		auto items = Rooms::getInstance().getRooms()[i]->getAllItems();
	
		// write rooms that only have items
		if (items && items->size() > 0)
		{
			// first thing is the roomid
			file << Rooms::getInstance().getRooms()[i]->getId() << " ";

			vector<unique_ptr<Item>>::iterator it;

			// loop through any items we found
			for (it = items->begin(); it != items->end(); ++it)
			{
				file << (*it)->getId();

				if (it != items->end() - 1)
				{
					file << " ";
				}
				else
				{
					file << endl;
				}
			}
		}
	}
	
	file.close();

	std::cout << "Saved" << endl;

}