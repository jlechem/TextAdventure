/*
	ActorBase.h
	Created By:			Justin LeCheminant
	Created On:			12-21-2017
	Last Modified:		01-02-2018
	Last Modified By:	Justin LeCheminant

	Notes: This is a base class for actors in the game. An actor can be a player, enemy, or NPC (Non Playable Character).

*/

#pragma once

#include "stdafx.h"

#include "Armor.h"
#include "Weapon.h"

class ActorBase
{
public:
	ActorBase();
	ActorBase(Room*);
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
	unique_ptr<Item> dropItem(string,bool);

	unique_ptr<Item>& getItem(string );

	vector<unique_ptr<Item>>* getInventory();

	bool addItem(unique_ptr<Item> item);

	Room* getCurrentRoom();
	void setCurrentRoom(Room*);

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

	Room* _currentRoom;

	unique_ptr<Item> findItem(string);

	unsigned int _level;

	vector<unique_ptr<Weapon>> _weapons;
	unique_ptr<Weapon> _currentWeapon;

	vector<unique_ptr<Armor>> _armors;

private:
	
};