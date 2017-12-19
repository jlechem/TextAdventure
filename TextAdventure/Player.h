/*
	Player.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: A class that represents the player in the game
*/


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
	bool dropItem(string);
	shared_ptr<Room> getCurrentRoom();
	bool Move(string);
	int getScore();
	void printInventory();

private:
	string _name;

	int _score;
	
	vector<unique_ptr<Item>> _items;
	
	shared_ptr<Room> _currentRoom;
	
	Directions convertDirection(string);
	
	unique_ptr<Item> findItem(string);

};