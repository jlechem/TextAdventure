#pragma once

#include "stdafx.h"

#include "GameSettings.h"
#include "rapidxml.hpp"

void PrintRoomDescription()
{

}

void LoadRooms(unique_ptr<vector<shared_ptr<Room>>> &rooms)
{

}

void LoadVerbs(unique_ptr<vector<string>> &verbs)
{

}

void LoadItems(unique_ptr<vector<unique_ptr<Item>>> &items)
{

}

void LoadTreasures(unique_ptr<vector<unique_ptr<Treasure>>> &treasures)
{

}

void LoadPlayer(unique_ptr<Player> &player)
{

}

void SaveGame() 
{

}

void LoadGame() 
{

}

bool GaveOver(unique_ptr<Player> player)
{
	return false;
}

void PrintInto(unique_ptr<GameSettings> &settings)
{
	cout << settings->getTitle() << endl << endl;

	// set the title of the command window
	if (settings->getShowIntroduction())
	{
		cout << settings->getIntroduction() << endl << endl; 
	}
}

void PrintEnding()
{

}

void PrintPlayerDeath()
{

}

void LoadGameData(unique_ptr<GameSettings> &settings)
{
	// TODO: get from the config file
	settings->setShowIntroduction(true);
	settings->setIntroduction("As the spaceship rover heads into deep space, the crew slowly awakes from cryogenic slumber...");
	settings->setTitle("Justins Space Adventure");
}