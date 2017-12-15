#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Room.h"

class Player
{
public:
	Player();
	Player(shared_ptr<Room>);
	~Player();

	vector<unique_ptr<Item>>* getInventory();
	bool addItem(string);
	unique_ptr<Item> dropItem(string);

	shared_ptr<Room> getCurrentRoom();

	bool Move(Directions);

	int getScore();

private:
	vector<unique_ptr<Item>> _items;
	
	shared_ptr<Room> _currentRoom;

	string _name;

	int _score;

	unique_ptr<Item> findItem(string);

};