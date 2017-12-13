// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Room.h"
#include "Player.h"
#include "Helpers.h"
#include "CommandHelpers.h"
#include "GameSettings.h"
#include "Command.h"

using namespace std;

int main()
{
	// declare some variables we need to use
	vector<shared_ptr<Room>> rooms;
	vector<unique_ptr<Item>> items;
	vector<unique_ptr<Treasure>> treasures;
	vector<string> verbs;

	unique_ptr<GameSettings> settings = make_unique<GameSettings>();
	
	// load our data
	LoadVerbs(verbs);
	LoadItems(items);
	LoadTreasures(treasures);
	LoadRooms(rooms, items, treasures);
	LoadGameData(settings);

	unique_ptr<Player> player = make_unique<Player>(rooms[0]);
	
	PrintInto(settings);

	Command command;

	// run the game loop
	while (!GaveOver(player))
	{
		PrintRoomDescription(player);
		PrintRoomExits(player);
		PrintRoomItems(player);
		PrintRoomTreasures(player);

		EnterCommand(command);
		ProcessCommand(command);

	}

    return 0;

}