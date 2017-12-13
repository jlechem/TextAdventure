// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Room.h"
#include "Player.h"
#include "Helpers.h"
#include "GameSettings.h"

using namespace std;

int main()
{
	// declare some variables we need to use
	// a few global search values
	unique_ptr<vector<shared_ptr<Room>>> rooms;
	unique_ptr<vector<unique_ptr<Item>>> items;
	unique_ptr<vector<unique_ptr<Treasure>>> treasures;
	unique_ptr<vector<string>> verbs;
	unique_ptr<GameSettings> settings = make_unique<GameSettings>();
	
	// the player
	unique_ptr<Player> player = make_unique<Player>();

	// load our data
	LoadVerbs(verbs);
	LoadItems(items);
	LoadTreasures(treasures);
	LoadRooms(rooms);
	LoadPlayer(player);
	LoadGameData(settings);

	PrintInto(settings);
	
	// run the game loop
	while (!GaveOver(std::move(player)))
	{

	}

    return 0;

}