#pragma once

#include "stdafx.h"

#include "Item.h"

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

	string getExitsString();
	map<Directions, shared_ptr<Room>>& getExits();
	void setExits(map<Directions, shared_ptr<Room>>&);
	void addExit(Directions, shared_ptr<Room>);

	unique_ptr<Item> findItem(string);

	string getItems();

private:
	int _id;
	string _name;
	string _description;
	string _shortDesctiption;
	string _exitString;
	string _itemsString;

	vector<unique_ptr<Item>> _items;
	map<Directions,shared_ptr<Room>> _exits;

	void generateExitString();
	void generateItemString();
	string convertDirectionToString(Directions);

};