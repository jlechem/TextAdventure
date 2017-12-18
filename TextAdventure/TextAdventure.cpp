// TextAdventure.cpp : Defines the entry point for the console application.
//

#pragma once

#include "stdafx.h"

#include "Room.h"
#include "Player.h"
#include "Helpers.h"
#include "GameSettings.h"
#include "Command.h"

using namespace std;

int main()
{
	// declare some variables we need to use
	vector<shared_ptr<Room>> rooms;
	vector<unique_ptr<Item>> items;
	unique_ptr<GameSettings> settings = make_unique<GameSettings>();
	unique_ptr<Command> command = make_unique<Command>();

	// load our data
	LoadVerbs(command);
	LoadItems(items);
	LoadRooms(rooms, items);
	LoadGameData(settings);

	// this is our main player object, we use it for running the game
	shared_ptr<Player> player = make_shared<Player>(rooms[0]);

	command->setPlayer(player);
	
	PrintInto(settings);
	
	// first thing we do is look to start the game
	command->setCommand("LOOK");
	ProcessCommand(command);
	
	// run the game loop
	while (!GaveOver(player))
	{
		EnterCommand(command);
		ProcessCommand(command);
	}

    return 0;

}