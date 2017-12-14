#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Treasure.h"
#include "Room.h"

class Player
{
public:
	Player();
	Player(shared_ptr<Room>);
	~Player();

	vector<unique_ptr<Item>>* getInventory();
	void addItem(unique_ptr<Item>);
	unique_ptr<Item> dropItem(string);

	vector<unique_ptr<Treasure>>* getTreasures();
	void addTreasure(unique_ptr<Treasure>);
	unique_ptr<Treasure> dropTreasure(string);

	shared_ptr<Room> getCurrentRoom();

	bool Move(Directions);

	int getScore();

private:
	vector<unique_ptr<Item>> _items;
	
	vector<unique_ptr<Treasure>> _treasures;

	shared_ptr<Room> _currentRoom;

	string _name;

	int _score;

	unique_ptr<Item> findItem(string);
	unique_ptr<Treasure> findTreasure(string);

};