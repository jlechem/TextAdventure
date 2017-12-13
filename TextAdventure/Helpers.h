#pragma once

#include "stdafx.h"

#include "GameSettings.h"
#include "rapidxml.hpp"
#include "Command.h"

shared_ptr<Room> FindRoom(int id)
{
	return NULL;
}

unique_ptr<Item> FindItem(int id)
{
	return NULL;
}

unique_ptr<Treasure> FindTreasure(int id)
{
	return NULL;
}

void PrintRoomDescription(unique_ptr<Player> &player)
{
	cout << player->getCurrentRoom()->getDescription() << endl;
}

void PrintRoomExits(unique_ptr<Player> &player)
{
	cout << "You can go: " << player->getCurrentRoom()->getExits() << endl;
}

void PrintRoomItems(unique_ptr<Player> &player)
{
	if (player->getCurrentRoom()->getItems().size() != 0)
	{
		cout << "You see the following items: " << player->getCurrentRoom()->getItems() << endl;
	}
}

void PrintRoomTreasures(unique_ptr<Player> &player)
{
	if (player->getCurrentRoom()->getTreasures().size() != 0)
	{
		cout << "You see the following treasures: " << player->getCurrentRoom()->getTreasures() << endl;
	}
}

void LoadRooms(vector<shared_ptr<Room>> &rooms, vector<unique_ptr<Item>> &items, vector<unique_ptr<Treasure>> &treasures)
{
	// TODO: load from the XML file

	// create two new temp rooms
	auto newRoom = make_shared<Room>();
	newRoom->setId(1);
	newRoom->setName("Brown Room");
	newRoom->setDescription("You are standing in a small brownish room with nothing in it but a door North");
	newRoom->setShortDescription("A small brown room");
	rooms.push_back(newRoom);

	auto newRoom2 = make_shared<Room>();
	newRoom2->setId(2);
	newRoom2->setName("Green Room");
	newRoom2->setDescription("You are standing in a small green room with a tacky carpet. There's a door South");
	newRoom2->setShortDescription("A small green room");
	rooms.push_back(newRoom2);

	// set exits
	rooms[0]->addExit(North, rooms[1]);
	rooms[1]->addExit(South, rooms[0]);

	// add items
	rooms[0]->addItem(std::move(items[0]));
	rooms[1]->addItem(std::move(items[1]));

	items.clear();

	// add treasures
	rooms[0]->addTreasure(std::move(treasures[0]));

	treasures.clear(); 

}

void LoadVerbs(unique_ptr<Command> &command)
{
	// TODO: load from the XML file
	command->getVerbs()->push_back("north");
	command->getVerbs()->push_back("n");
	command->getVerbs()->push_back("south");
	command->getVerbs()->push_back("s");
	command->getVerbs()->push_back("look");
	command->getVerbs()->push_back("l");
	command->getVerbs()->push_back("east");
	command->getVerbs()->push_back("e");
	command->getVerbs()->push_back("w");
	command->getVerbs()->push_back("west");
	command->getVerbs()->push_back("take");
	command->getVerbs()->push_back("drop");
	command->getVerbs()->push_back("exits");
	command->getVerbs()->push_back("take");
	command->getVerbs()->push_back("t");
	command->getVerbs()->push_back("quit");
	command->getVerbs()->push_back("q");
	command->getVerbs()->push_back("exit");
}

void LoadItems(vector<unique_ptr<Item>> &items)
{
	// TODO: load from the XML file

	// make two new temp items
	auto newItem = make_unique<Item>();
	newItem->setId(1);
	newItem->setName("stick");
	newItem->setDescription("a sharp pointy stick");
	newItem->setScore(100);
	items.push_back(std::move(newItem));

	auto newItem2 = make_unique<Item>();
	newItem2->setId(2);
	newItem2->setName("black rock");
	newItem2->setDescription("a small, round, and very shiny black rock");
	newItem2->setScore(5000);
	items.push_back(std::move(newItem2));

}

void LoadTreasures(vector<unique_ptr<Treasure>> &treasures)
{
	// TODO: load from the XML file

	// make a new temp treasure
	auto newItem = make_unique<Treasure>();
	newItem->setId(1);
	newItem->setName("Golden Egg");
	newItem->setDescription("An egg laid by the golden goose");
	newItem->setScore(8000);
	treasures.push_back(std::move(newItem));

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

bool GaveOver(unique_ptr<Player> &player)
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