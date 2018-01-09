/*
	File:			HelpCommand.cpp
	Created By:		Justin LeCheminant
	Created On:		01-02-2018
	Last Modified:	1-9-2018

	Notes:			Implementation of the HelpCommand class.

*/

#include "stdafx.h"

#include "HelpCommand.h"
#include "rapidxml.hpp"

HelpCommand::HelpCommand()
	: CommandInterface()
{
}

HelpCommand::HelpCommand(string command)
	: CommandInterface(command)
{
}

HelpCommand::HelpCommand(string command, Player* player)
	: CommandInterface(command,player) 
{
}

HelpCommand::HelpCommand(string command, Player * player, Parser * parser)
	: CommandInterface(command,player,parser)
{
}

HelpCommand::~HelpCommand()
{
}

void HelpCommand::process()
{
	ifstream inputFile("help.dat", ifstream::in);

	if (inputFile.is_open())
	{
		_commandResult = (std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>()));

		inputFile.close();

	}
	else
	{
		throw "Help file wasn't found";
	}


	cout << endl << _commandResult << endl;

	_commandResult.clear();

}