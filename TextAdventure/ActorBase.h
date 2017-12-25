/*
	ActorBase.h
	Created By:			Justin LeCheminant
	Created On:			12-21-2017
	Last Modified:		12-24-2017
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

	unsigned int getScore();
	void setScore(unsigned int);
	void addToScore(unsigned int);

	unsigned int getId();
	void setId(unsigned int);

	bool addItem(string);
	bool dropItem(string);

	vector<unique_ptr<Item>>* getInventory();

	shared_ptr<Room> getCurrentRoom();
	
	bool Move(string);
	
	unsigned long getMoveCount();

	void attack(shared_ptr<ActorBase>);
	void defend(shared_ptr<ActorBase>);

	unsigned int getHitPoints();
	void setHitPoints(unsigned int);

	unsigned int getLevel();
	void setLevel(unsigned int);
	void levelUp();

protected:
	string _name;
	string _description;
	unsigned int _score;
	unsigned int _id;
	unsigned long _numberOfMoves;
	unsigned int _hitpoints;

	vector<unique_ptr<Item>> _items;

	shared_ptr<Room> _currentRoom;

	unique_ptr<Item> findItem(string);

	unsigned int _level;

private:
	
};