/*
	ActorBase.h
	Created By:			Justin LeCheminant
	Created On:			12-20-2017
	Last Modified:		12-20-2017
	Last Modified By:	Justin LeCheminant

	Notes: This is a base class for actors in the game. An actor can be a player, enemy, or NPC (Non Playable Character).

*/

#pragma once

#include "stdafx.h"
#include "Room.h"
#include "Item.h"

class ActorBase
{
public:
	ActorBase();
	ActorBase(shared_ptr<Room>);
	~ActorBase();
	
	string getName();
	void setName(string);

	string getDescription();
	void setDescription(string);

	int getScore();
	void setScore(int);
	void addToScore(int);

	int getId();
	void setId(int);

	bool addItem(string);
	bool dropItem(string);

	vector<unique_ptr<Item>>* getInventory();

	shared_ptr<Room> getCurrentRoom();
	
	bool Move(string);
	
	unsigned long getMoveCount();

protected:
	string _name;
	string _description;
	int _score;
	int _id;
	unsigned long _numberOfMoves;

	vector<unique_ptr<Item>> _items;

	shared_ptr<Room> _currentRoom;

	unique_ptr<Item> findItem(string);

private:
	
};