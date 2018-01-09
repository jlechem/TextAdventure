/*
	LoadCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		12-21-2017
	Last Modified:	1-9-2018

	Notes:			Implemenation of the LoadCommand class.

*/

#include "stdafx.h"

#include "LoadCommand.h"

LoadCommand::LoadCommand()
	: CommandInterface()
{
}

LoadCommand::LoadCommand(string command)
	: CommandInterface(command)
{
}

LoadCommand::LoadCommand(string command,Player* player)
	: CommandInterface(command,player)
{
} 

LoadCommand::LoadCommand(string command, Player * player, Parser* parser)
	: CommandInterface(command,player, parser )
{
}

LoadCommand::~LoadCommand()
{
}

void LoadCommand::process()
{
	// we need to read from the SAVE\save.dat folder
	ifstream file("SAVE\save.dat", ios::in | ios::binary);
	
	if (file)
	{
		vector<int> itemIds;

		// first read the current room id
		auto roomId = 0;
		file >> roomId;
		
		string line;
		
		getline( file, line );

		// find the room that matches our id
		//auto room = findRoom(roomId);
		auto room = nullptr;

		if (room)
		{
			_player->setCurrentRoom(room);
			//_commandResult = room->getLongDescription();
		}
		else
		{
			_commandResult = "An error occured loading game data";
		}
	}

	cout << endl << _commandResult << endl;

}