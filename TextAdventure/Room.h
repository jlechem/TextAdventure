#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Treasure.h"

class Room
{
public:
	Room();
	~Room();

	Room(int, string, string, string);

	int getId();
	void setId(int);

	string getName();
	void setName(string);

	string getDescription();
	void setDescription(string);

	string getShortDescription();
	void setShortDescription(string);

	void addItem(unique_ptr<Item>);
	void removeItem(string);
	void removeItem(unique_ptr<Item>);

	void addTreasure(unique_ptr<Treasure>);
	void removeTreasure(string);
	void removeTreasure(unique_ptr<Treasure>);

	string getExitsString();
	map<Directions, shared_ptr<Room>>& getExits();
	void setExits(map<Directions, shared_ptr<Room>>&);
	void addExit(Directions, shared_ptr<Room>);

	string getItems();
	string getTreasures();

private:
	int _id;
	string _name;
	string _description;
	string _shortDesctiption;
	string _exitString;
	string _itemsString;
	string _treasuresString;

	vector<unique_ptr<Item>> _items;
	vector<unique_ptr<Treasure>> _treasures;
	map<Directions,shared_ptr<Room>> _exits;

	void generateExitString();
	void generateItemString();
	void generateTreasureString();
	string convertDirectionToString(Directions);

};