/*
	Player.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-19-2017
	Notes: A class that represents the player in the game
*/


#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Room.h"
#include "ObjectBase.h"
#include "Utils.h"

class Player: public ObjectBase
{
public:
	Player();
	Player(shared_ptr<Room>);
	~Player();

	vector<unique_ptr<Item>>* getInventory();
	bool addItem(string);
	bool dropItem(string);
	shared_ptr<Room> getCurrentRoom();
	bool Move(string);
	int getScore();
	void printInventory();
	
private:
	vector<unique_ptr<Item>> _items;
	
	shared_ptr<Room> _currentRoom;
	
	unique_ptr<Item> findItem(string);

};