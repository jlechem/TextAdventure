/*
	File:				TextAdventure.cpp
	Created By:			Justin LeCheminant
	Created On:			12-18-2017
	Last Modified:		9-18-2019
	Last Modified By:	Justin LeCheminant

	Notes:				This is the main game running part.

*/

#pragma once

#include "stdafx.h"

#include "Articles.h"
#include "Articles2.h"
#include "Room.h"
#include "Player.h"
#include "GameSettings.h"
#include "CommandInterface.h"
#include "CommandFactory.h"
#include "rapidxml.hpp"
#include "Item.h"
#include "Utils.h"
#include "Rooms.h"
#include "Verbs.h"

Room* FindRoom(int id)
{
	vector<Room*>::iterator it;

	Room* result = nullptr;

	for (it = Rooms::getInstance().getRooms().begin(); it != Rooms::getInstance().getRooms().end(); ++it)
	{
		if ((*it)->getId() == id)
		{
			result = (*it);
			break;
		}
	}

	return result;
}

unique_ptr<Item> FindItem(int id, vector<unique_ptr<Item>> &items)
{
	vector<unique_ptr<Item>>::iterator it;

	unique_ptr<Item> result = nullptr;

	for (it = items.begin(); it != items.end(); ++it)
	{
		if ((*it)->getId() == id)
		{
			result = std::move((*it));
			items.erase(it);
			break;
		}
	}

	return result;
	
}

void LoadXML(string& xmlBuffer, const string& filename)
{
	ifstream inputFile(filename, ifstream::in);
	
	if (inputFile.is_open())
	{
		xmlBuffer = (std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>()));

		inputFile.close();

	}
	else
	{
		throw "config.xml file wasn't found.";
	}
}

void LoadRooms(vector<unique_ptr<Item>> &items, rapidxml::xml_document<>* document)
{
	// get the first config node
	rapidxml::xml_node<>* rootNode = document->first_node("config");

	if (rootNode)
	{
		// move down to the next node, GameData
		rootNode = rootNode->first_node();

		// move down to the next node group, Player
		rootNode = rootNode->next_sibling();

		// move down to the next node group, Items
		rootNode = rootNode->next_sibling();

		// move down to the next node group, Rooms
		rootNode = rootNode->next_sibling();

		// this is our Room Node
		rapidxml::xml_node<>* roomNode = rootNode->first_node();

		while (roomNode)
		{
			Room* newRoom = new Room();

			// this is our Room attribute Node, starts at Id
			rapidxml::xml_node<>* attributeNode = roomNode->first_node();
			newRoom->setId(atoi(attributeNode->value()));

			// name
			attributeNode = attributeNode->next_sibling();
			newRoom->setName(attributeNode->value());

			// description
			attributeNode = attributeNode->next_sibling();
			newRoom->setDescription(attributeNode->value());

			// move to the Items group
			attributeNode = attributeNode->next_sibling();

			// get the first Item node if we have any
			rapidxml::xml_node<>* itemNode = attributeNode->first_node();

			// iterate through the items
			while (itemNode)
			{
				rapidxml::xml_node<>* itemIdNode = itemNode->first_node();

				// we should be on the item id
				auto itemID = atoi(itemIdNode->value());

				// get the item that has this ID
				auto newItem = FindItem(itemID, items);

				// if we found an item, add it to our room
				if (newItem)
				{
					newRoom->addItem(std::move(newItem));
				}

				// get next exit node
				itemNode = itemNode->next_sibling();

			}

			// add thw new room to our vector
			Rooms::getInstance().getRooms().push_back(newRoom);

			// move to the next room
			roomNode = roomNode->next_sibling();
		}

		// move down to the next node group, RoomExits
		rootNode = rootNode->next_sibling();

		// get the first room node if we have one
		roomNode = rootNode->first_node();

		// loop through our room nodes
		while (roomNode)
		{
			// move down to the room id
			rapidxml::xml_node<>* attributeNode = roomNode->first_node();
			auto roomID = atoi(attributeNode->value());

			// find the room with that ID
			auto room = FindRoom(roomID);

			// if we have a room that matches that, then add some exits
			if (room)
			{
				// move to the exits group node
				attributeNode = attributeNode->next_sibling();

				// move down to the first exit if we have any
				rapidxml::xml_node<>* exitNode = attributeNode->first_node();

				// loop through our exits if we have any
				while (exitNode)
				{
					// move down to the room id and parse it
					attributeNode = exitNode->first_node();
					roomID = atoi(attributeNode->value());

					// move to the direction node
					attributeNode = attributeNode->next_sibling();
					auto direction = Utilities::convertDirection(attributeNode->value());

					// find a room with this ID
					auto exitRoom = FindRoom(roomID);

					// if we have a room with this ID then add it to our map
					if (exitRoom)
					{
						room->addExit(direction, exitRoom);

						// move to the next Exit node in the Exits group
						exitNode = exitNode->next_sibling();
					}
				}

				// move to the next exit node
				roomNode = roomNode->next_sibling();

			}

		}

		items.clear();

	}
}

void LoadItems(vector<unique_ptr<Item>> &items, rapidxml::xml_document<>* document)
{
	// get the first config node
	rapidxml::xml_node<>* rootNode = document->first_node("config");

	if (rootNode)
	{
		// move down to the next node, GameData
		rootNode = rootNode->first_node();

		// get the next sibling, player node
		rootNode = rootNode->next_sibling();

		// get the next sibling, Items node
		rootNode = rootNode->next_sibling();

		// put us on the first Item sub group (if it exists)
		rapidxml::xml_node<>* itemNode = rootNode->first_node();

		while (itemNode)
		{
			auto newItem = make_unique<Item>();

			// attributes, this will put us on Id
			rapidxml::xml_node<>* attributeNode = itemNode->first_node();
			newItem->setId(atoi(attributeNode->value()));
			
			// name
			attributeNode = attributeNode->next_sibling();
			newItem->setName(attributeNode->value());

			// description
			attributeNode = attributeNode->next_sibling();
			newItem->setDescription(attributeNode->value());

			// item type
			attributeNode = attributeNode->next_sibling();
			newItem->setItemType(attributeNode->value() == "item" ? ItemType::BaseItem : ItemType::Treasure);

			// item score
			attributeNode = attributeNode->next_sibling();
			newItem->setScore(atoi(attributeNode->value()));

			// can open
			attributeNode = attributeNode->next_sibling();
			newItem->setCanOpen(Utilities::toBoolean(attributeNode->value()));

			// can take
			attributeNode = attributeNode->next_sibling();
			newItem->setCanTake(Utilities::toBoolean(attributeNode->value()));

			// sub item capacity
			attributeNode = attributeNode->next_sibling();
			newItem->setSubItemCapacity(atoi(attributeNode->value()));
			
			// size type (passing for now, not sure about this yet)
			attributeNode = attributeNode->next_sibling();

			// move to the alternate names group
			attributeNode = attributeNode->next_sibling();
			
			// move to the first child node in the group, if we have a group
			attributeNode = attributeNode->first_node();

			// loop through the alternate names
			while (attributeNode)
			{
				newItem->addAlternateName(attributeNode->value());
				attributeNode = attributeNode->next_sibling();
			}

			items.push_back(std::move(newItem));

			// move to the next sibling node
			itemNode = itemNode->next_sibling();

		}
	}
}

bool IsGameOver(Player* player)
{
	return player->getIsGameOver();
}

void PrintInto(GameSettings settings)
{
	cout << settings.getTitle() << endl << endl;

	// set the title of the command window
	if (settings.getShowIntroduction())
	{
		cout << settings.getIntroduction() << endl << endl;
	}
}

void PrintEnding(Player* player, GameSettings settings)
{
	auto items = player->getInventory();

	vector<unique_ptr<Item>>::iterator it;

	// print out the score, etc
	cout << endl << endl << "Thanks for playing " << settings.getTitle() << endl << endl
		<< "You made a total of: " << player->getMoveCount() << " moves" << endl
		<< "You have the following items: " << endl;
	
	for (it = items->begin(); it != items->end(); ++it)
	{
		cout << (*it)->getName() << endl;
	}

	cout << "Thanks for playing. Your final score is: " << player->getScore() << endl;

}

void LoadGameData(GameSettings& settings, rapidxml::xml_document<>* document)
{
	// get the first config node
	rapidxml::xml_node<>* rootNode = document->first_node("config");

	if (rootNode)
	{
		// move down to the next node, GameData
		rootNode = rootNode->first_node();

		// move down to the next node, Name (Title)
		rootNode = rootNode->first_node();
		settings.setTitle(string(rootNode->value()));

		// move down to the next node, Version
		rootNode = rootNode->next_sibling();

		// move down to the next node, DisplayIntroduction
		rootNode = rootNode->next_sibling();
		settings.setShowIntroduction(rootNode->value() == "y" || rootNode->value() == "yes");

		// move down to the next node, Introduction
		rootNode = rootNode->next_sibling();
		settings.setIntroduction(string(rootNode->value()));
	}
}

void EnterCommand(unique_ptr<CommandInterface>& command, Player* player )
{
	string commandLine;

	do
	{
		cout << endl << "?> ";
		getline(cin, commandLine);
		Utilities::trim(commandLine);

		if (commandLine.empty())
		{
			cout << "What do you want to do?" << endl;
		}
	} while (commandLine.size() <= 0);
	
	Utilities::toLower(commandLine);

	command = CommandFactory::getCommand(commandLine, player);
	
}

void ProcessCommand(unique_ptr<CommandInterface>& command)
{
	// process then clear our pointer to make way for the new Dependency Injection
	command->process();
	command = nullptr;
}

void LoadWords()
{
	Verbs::getInstance().Load("verbs.dat");
	Articles::getInstance().Load("articles.dat");
	Articles2::getInstance().Load("articles2.dat");
}

/*
	Main function
*/
int main(int argc, const char** argv )
{
	try
	{
		// declare some variables we need to use
		vector<unique_ptr<Item>> items;

		GameSettings settings;	
														
		string xml;															
		string filename;													

		// validate we have an XML config file to use
		if (argc != 2)
		{
			filename = "config.xml";
		}
		else
		{
			filename = argv[1];
		}	

		cout << "Loading data" << endl << "Loading XML...";

		LoadXML(xml, filename);
		
		cout << "Done" << endl << "Parsing XML...";

		rapidxml::xml_document<> doc;
		doc.parse<0>((char *)xml.c_str());

		cout << "Done" << endl << "Loading Game Settings...";

		LoadGameData(settings, &doc);
		
		cout << "Done" << endl << "Loading Items...";
		
		LoadItems(items, &doc);

		cout << "Done" << endl << "Loading Rooms...";

		LoadRooms(items, &doc);

		cout << "Done" << endl << "Loading Words...";

		LoadWords();

		cout << "Done" << endl << "All game data loaded" << endl << endl;

		// this is our main player object, we use it for running the game
		auto player = new Player(Rooms::getInstance().getRooms()[0]);

		PrintInto(settings);
		
		auto command = CommandFactory::getCommand("LOOK", player);
		ProcessCommand(command);
		
		// run the game loop
		while (!IsGameOver(player))
		{
			EnterCommand(command, player);
			ProcessCommand(command);
		}

		PrintEnding(player, settings);

		delete player;

	}
	catch (exception* ex)
	{
		cout << " An error occured, " << ex->what() << endl;
	}
	catch (int errorNumber)
	{
		cout << " An error occured, " << errorNumber << endl;
	}
	catch (char* message)
	{
		cout << " An error occured, " << message << endl;
	}
	catch (...)
	{
		cout << " An error occured" << endl;
	}

	cout << endl << endl;

	// This is a WINDOWS only call, if you want to get the same thing in another OS you
	// will need to use a different system call
	system("pause");

    return 0;

}