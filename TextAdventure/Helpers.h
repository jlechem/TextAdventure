#pragma once

#include "stdafx.h"

#include "rapidxml.hpp"

void PrintRoomDescription()
{

}

void LoadRooms(unique_ptr<vector<shared_ptr<Room>>> rooms)
{

}

void LoadVerbs(unique_ptr<vector<string>> verbs)
{

}

void LoadItems(unique_ptr<vector<unique_ptr<Item>>> items)
{

}

void LoadTreasures(unique_ptr<vector<unique_ptr<Treasure>>> treasures)
{

}

void LoadPlayer(unique_ptr<Player> player)
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

void PrintInto()
{

}

void PrintEnding()
{

}

void PrintPlayerDeath()
{

}