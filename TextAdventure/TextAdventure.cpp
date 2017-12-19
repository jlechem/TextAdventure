/*
	TextAdventure.cpp
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
*/

#pragma once

#include "stdafx.h"

#include "Room.h"
#include "Player.h"
#include "GameSettings.h"
#include "Command.h"
#include "rapidxml.hpp"
#include "Item.h"

using namespace std;

void LoadXML(string& xmlBuffer)
{
	ifstream inputFile("config.xml", ifstream::in);
	
	if (inputFile.is_open())
	{
		xmlBuffer = (std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>()));
	}

	inputFile.close();
	
}

void LoadRooms(vector<shared_ptr<Room>> &rooms, vector<unique_ptr<Item>> &items, rapidxml::xml_document<>* document)
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
	string verb;

	ifstream inputFile("verbs.dat", ifstream::in);

	if (inputFile.is_open())
	{
		while (inputFile >> verb)
		{
			command->getVerbs().push_back(verb);
		}
	}

	inputFile.close();

	sort(command->getVerbs().begin(), command->getVerbs().end());

}

void LoadItems(vector<unique_ptr<Item>> &items, rapidxml::xml_document<>* document)
{
	// TODO: load from the XML file

	// make two new temp items
	auto newItem = make_unique<Item>();
	newItem->setId(1);
	newItem->setName("stick");
	newItem->setDescription("a sharp pointy stick");
	newItem->setScore(100);
	newItem->setType(ItemType::BaseItem);
	newItem->addAlternateName("stick");
	newItem->addAlternateName("pointy stick");
	newItem->addAlternateName("sharp stick");
	newItem->addAlternateName("sharp pointy stick");
	items.push_back(std::move(newItem));

	auto newItem2 = make_unique<Item>();
	newItem2->setId(2);
	newItem2->setName("black rock");
	newItem2->setDescription("a small, round, and very shiny black rock");
	newItem2->setScore(5000);
	newItem2->setType(ItemType::BaseItem);
	newItem2->addAlternateName("black rock");
	newItem2->addAlternateName("rock");

	items.push_back(std::move(newItem2));

	auto newItem3 = make_unique<Item>();
	newItem3->setId(3);
	newItem3->setName("Golden Egg");
	newItem3->setDescription("An egg laid by the golden goose.");
	newItem3->setScore(50000);
	newItem3->setType(ItemType::Treasure);
	newItem3->addAlternateName("egg");
	newItem3->addAlternateName("golden egg");
	newItem3->addAlternateName("goose egg");
	items.push_back(std::move(newItem3));

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

void LoadGameData(unique_ptr<GameSettings> &settings, rapidxml::xml_document<>* document)
{
	// get the first config node
	rapidxml::xml_node<>* rootNode = document->first_node("config");

	if (rootNode)
	{
		// move down to the next node, GameData
		rootNode = rootNode->first_node();

		// move down to the next node, Name (Title)
		rootNode = rootNode->first_node();
		settings->setTitle(string(rootNode->value()));

		// move down to the next node, Version
		rootNode = rootNode->next_sibling();

		// move down to the next node, DisplayIntroduction
		rootNode = rootNode->next_sibling();
		settings->setShowIntroduction(rootNode->value() == "y" || rootNode->value() == "yes");

		// move down to the next node, Introduction
		rootNode = rootNode->next_sibling();
		settings->setIntroduction(string(rootNode->value()));
	}
}

void EnterCommand(unique_ptr<Command>& command)
{
	string commandLine;

	cout << endl << "?> ";

	getline(cin, commandLine);

	transform(commandLine.begin(), commandLine.end(), commandLine.begin(), tolower);

	command->setCommand(commandLine);

}

void ProcessCommand(unique_ptr<Command>& command)
{
	command->process();
}

/*
	Main function
*/
int main()
{
	try
	{
		// declare some variables we need to use
		vector<shared_ptr<Room>> rooms;
		vector<unique_ptr<Item>> items;
		unique_ptr<GameSettings> settings = make_unique<GameSettings>();
		unique_ptr<Command> command = make_unique<Command>();

		string xml;

		// load our data
		LoadXML(xml);

		rapidxml::xml_document<> doc;
		doc.parse<0>((char *)xml.c_str());

		LoadVerbs(command);
		LoadItems(items, &doc);
		LoadRooms(rooms, items, &doc);
		LoadGameData(settings, &doc);

		// this is our main player object, we use it for running the game
		shared_ptr<Player> player = make_shared<Player>(rooms[0]);

		command->setPlayer(player);

		system("CLS");

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
	}
	catch (exception ex)
	{
		cout << "An error occured: " << ex.what() << endl;
	}

    return 0;

}