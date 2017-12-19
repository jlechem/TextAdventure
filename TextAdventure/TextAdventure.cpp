/*
	TextAdventure.cpp
	Created By:			Justin LeCheminant
	Created On:			12-18-2017
	Last Modified:		12-19-2017
	Last Modified By:	Justin LeCheminant
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

/// <summary>
/// Loads the XML.
/// </summary>
/// <param name="xmlBuffer">The XML buffer.</param>
void LoadXML(string& xmlBuffer)
{
	ifstream inputFile("config.xml", ifstream::in);
	
	if (inputFile.is_open())
	{
		xmlBuffer = (std::string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>()));
	}

	inputFile.close();
	
}

/// <summary>
/// Loads the rooms.
/// </summary>
/// <param name="rooms">The rooms.</param>
/// <param name="items">The items.</param>
/// <param name="document">The document.</param>
void LoadRooms(vector<shared_ptr<Room>> &rooms, vector<unique_ptr<Item>> &items, rapidxml::xml_document<>* document)
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
			auto newRoom = make_shared<Room>();

			// this is our Room attribute Node, starts at Id
			rapidxml::xml_node<>* attributeNode = roomNode->first_node();			
			newRoom->setId(atoi(attributeNode->value()));
			
			// name
			attributeNode = attributeNode->next_sibling();
			newRoom->setName(attributeNode->value());
			
			// description
			attributeNode = attributeNode->next_sibling();
			newRoom->setDescription(attributeNode->value());
			
			// handle exits

			// handle items

			rooms.push_back(newRoom);

			// move to the next room
			roomNode = roomNode->next_sibling();
		}
	}
	
	items.clear();
}

void FindRoom(int ind)
{

}

void FindItem(int id)
{

}

/// <summary>
/// Loads the allowed verbs from the verbs.data file.
/// </summary>
/// <param name="command">The command.</param>
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

/// <summary>
/// Loads the items from the xml config file.
/// </summary>
/// <param name="items">The items.</param>
/// <param name="document">The document.</param>
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

			// score
			/*attributeNode = attributeNode->next_sibling();
			newItem->setScore(atoi(attributeNode->value()));*/

			// item type
			attributeNode = attributeNode->next_sibling();
			newItem->setType(attributeNode->value() == "item" ? ItemType::BaseItem : ItemType::Treasure);

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

/// <summary>
/// Saves the game.
/// </summary>
void SaveGame()
{

}

/// <summary>
/// Loads the game.
/// </summary>
void LoadGame()
{

}

/// <summary>
/// Determines whether [is gave over] [the specified player].
/// </summary>
/// <param name="player">The player.</param>
/// <returns>
///   <c>true</c> if [is gave over] [the specified player]; otherwise, <c>false</c>.
/// </returns>
bool IsGaveOver(shared_ptr<Player> &player)
{
	return false;
}

/// <summary>
/// Prints the into.
/// </summary>
/// <param name="settings">The settings.</param>
void PrintInto(unique_ptr<GameSettings> &settings)
{
	cout << settings->getTitle() << endl << endl;

	// set the title of the command window
	if (settings->getShowIntroduction())
	{
		cout << settings->getIntroduction() << endl << endl;
	}
}

/// <summary>
/// Prints the ending.
/// </summary>
/// <param name="player">The player.</param>
void PrintEnding(unique_ptr<Player>& player)
{
	cout << endl << "Thanks for playing. You final score is: " << player->getScore() << endl;
}

/// <summary>
/// Loads the game data.
/// </summary>
/// <param name="settings">The settings.</param>
/// <param name="document">The document.</param>
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

/// <summary>
/// Enters the command.
/// </summary>
/// <param name="command">The command.</param>
void EnterCommand(unique_ptr<Command>& command)
{
	string commandLine;

	cout << endl << "?> ";

	getline(cin, commandLine);

	transform(commandLine.begin(), commandLine.end(), commandLine.begin(), tolower);

	command->setCommand(commandLine);

}

/// <summary>
/// Processes the command.
/// </summary>
/// <param name="command">The command.</param>
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
		while (!IsGaveOver(player))
		{
			EnterCommand(command);
			ProcessCommand(command);
		}
	}
	catch (exception* ex)
	{
		cout << "An error occured: " << ex->what() << endl;
	}

    return 0;

}