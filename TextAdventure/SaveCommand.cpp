/*
	File:			SaveCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-26-2018

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
	string filename = "";

	cout << "Enter filename (default save.dat)>? ";
	getline(cin, filename);

	Utilities::trim(filename);

	filename = filename.empty() ? filename = "SAVE\\save.dat" :  "SAVE\\" + filename;

	// open file for output in binary truncating any existing data
	ofstream file(filename, ios::out | /*ios::binary | */ ios::trunc);

	// the room id the player is in, followed by their score
	file << _player->getCurrentRoom()->getId() << " " << _player->getScore() << " ";

	// then the players items
	saveItems(_player->getItems(), file);

	saveRooms(file);

	file.close();

	std::cout << "Saved" << endl;

}

void SaveCommand::saveItems(vector<unique_ptr<Item>>& items, ofstream& file)
{
	vector<unique_ptr<Item>>::iterator it;

	for (it = items.begin(); it != items.end(); ++it)
	{
		string openStatus = "";

		if ((*it)->getCanOpen())
		{
			openStatus = (*it)->getIsOpen() ? "O" : "C";
		}
		else
		{
			openStatus = "X";
		}

		file << (*it)->getId() << " " << openStatus << " ";

		// now print any sub items
		if ((*it)->getSubItemCount() > 0)
		{
			file << ": ";

	//		saveItems((*it)->getItems(),file);

		}
	}
}

void SaveCommand::saveRooms(ofstream& file)
{
	vector<unique_ptr<Item>>::iterator it;
}