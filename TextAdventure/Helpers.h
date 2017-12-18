#pragma once

#include "stdafx.h"

#include "GameSettings.h"
#include "rapidxml.hpp"
#include "Command.h"
#include "Room.h"
#include "Player.h"
#include "Item.h"

void PrintRoomExits(unique_ptr<Player> &player)
{
	cout << "You can go: " << player->getCurrentRoom()->getExitsString() << endl;
}

void PrintRoomItems(unique_ptr<Player> &player)
{
	if (player->getCurrentRoom()->getItems().size() != 0)
	{
		cout << "You see the following items: " << player->getCurrentRoom()->getItems() << endl;
	}
}

void PrintRoomDescription(unique_ptr<Player> &player)
{
	cout << endl << player->getCurrentRoom()->getDescription() << endl;

	PrintRoomExits(player);
	PrintRoomItems(player);
}

void LoadRooms(vector<shared_ptr<Room>> &rooms, vector<unique_ptr<Item>> &items)
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
	rooms[0]->addItem(std::move(items[2]));

	rooms[1]->addItem(std::move(items[1]));
	
	items.clear();

}

void LoadVerbs(unique_ptr<Command> &command)
{
	// load from the verbs.dat file
	string verb;

	ifstream inputFile("verbs.dat", ifstream::in);

	if (inputFile.is_open())
	{
		while (inputFile >> verb)
		{
			command->getVerbs()->push_back(verb);
		}
	}

	inputFile.close();

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
	newItem->setType(ItemType::BaseItem);
	items.push_back(std::move(newItem));

	auto newItem2 = make_unique<Item>();
	newItem2->setId(2);
	newItem2->setName("black rock");
	newItem2->setDescription("a small, round, and very shiny black rock");
	newItem2->setScore(5000);
	newItem2->setType(ItemType::BaseItem);
	items.push_back(std::move(newItem2));

	auto newItem3 = make_unique<Item>();
	newItem3->setId(3);
	newItem3->setName("Golden Egg");
	newItem3->setDescription("An egg laid by the golden goose.");
	newItem3->setScore(50000);
	newItem3->setType(ItemType::Treasure);
	items.push_back(std::move(newItem3));

}

void LoadPlayer(shared_ptr<Player> &player)
{
}

void SaveGame() 
{

}

void LoadGame() 
{

}

bool GaveOver(shared_ptr<Player> &player)
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

void PrintEnding(unique_ptr<Player>& player)
{
	cout << endl << "Thanks for playing. You final score is: " << player->getScore() << endl;
}

void LoadGameData(unique_ptr<GameSettings> &settings)
{
	// TODO: get from the config file
	settings->setShowIntroduction(true);
	settings->setIntroduction("As the spaceship rover heads into deep space, the crew slowly awakes from cryogenic slumber...");
	settings->setTitle("Justins Space Adventure");
}

void EnterCommand(unique_ptr<Command>& command)
{
	string commandLine;

	cout << "?> ";

	getline(cin, commandLine);

	transform(commandLine.begin(), commandLine.end(), commandLine.begin(), tolower);

	command->setCommand(commandLine);

}

//void PrintInvalidCommand(unique_ptr<Command>& command)
//{
//	string error;
//	error = command->getCommand().size() != 0 ? "I don't understand how to '" + command->getCommand() + "'" : "You didn't enter anything";
//	cout << error << endl;
//}

void PrintCommandResult(unique_ptr<Command>& command)
{
	cout << endl << command->getCommandResult() << endl;
}

void ProcessCommand(unique_ptr<Command>& command)
{
	command->Process();
	command->PrintResult();
}

//switch (command->getActionType())
//{
//case ActionType::Action:
//	PrintAction(command);
//	break;
//
//case ActionType::Look:
//	PrintRoomDescription(player);
//	break;
//
//case ActionType::Movement:
//	if (!IsValidMove(player, getDirection(command->getCommand())))
//	{
//		PrintInvalidMove(command->getCommand());
//	}
//	else
//	{
//		PrintRoomDescription(player);
//	}
//
//	break;
//
//case ActionType::Inventory:
//	PrintInventory(player);
//	break;
//
//case ActionType::Quit:
//	PrintEnding(player);
//	exit(0);
//	break;
//
//case ActionType::Save:
//	SaveGame();
//	break;
//
//case ActionType::Take:
//	TakeItem(command, player);
//	break;
//
//case ActionType::Drop:
//	DropItem(command, player);
//	break;
//
//default:
//	break;
//
//}