/*
	File:						Player.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	1-9-2018

	Notes:					A class that represents the player in the game

*/

#pragma once

#include "stdafx.h"

#include "Item.h"
#include "Room.h"
#include "ObjectBase.h"
#include "Utils.h"
#include "ActorBase.h"

class Player: public ActorBase
{
public:
	Player();
	Player(Room*);
	~Player();

	void printInventory();
	
	string takeAllItems();

	string dropAllItems();

	bool getIsGameOver();
	void setIsGameOver(bool);

	string toString();

	unsigned long getTotalExperience();
	void setTotalExperience(unsigned long);

	unsigned long getExperienceToNextLevel();
	void setExperienceToNextLevel(unsigned long);

	string openItem(string);
	string closeItem(string);

private:
	bool _isGameOver;

	unsigned long _totalExperience;
	
	unsigned long _experienceToNextLevel;

};