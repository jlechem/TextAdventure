#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Treasure.h"
#include "Room.h"

class Player
{
public:
	Player();
	~Player();

	shared_ptr<vector<unique_ptr<Item>>> getInventory();
	void addItem(unique_ptr<Item>);
	unique_ptr<Item> dropItem(string);

	shared_ptr<vector<unique_ptr<Treasure>>> getTreasures();
	void addTreasure(unique_ptr<Treasure>);
	unique_ptr<Treasure> dropTreasure(string);

	bool Move(Directions);

private:
	shared_ptr<vector<unique_ptr<Item>>> _items;

	shared_ptr<vector<unique_ptr<Treasure>>> _treasures;

	shared_ptr<Room> _currentRoom;

	string _name;

	int _score;

	unique_ptr<Item> findItem(string);
	unique_ptr<Treasure> findTreasure(string);

};