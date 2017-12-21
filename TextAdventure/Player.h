/*
	Player.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-20-2017
	Notes: A class that represents the player in the game
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
	Player(shared_ptr<Room>);
	~Player();

	void printInventory();
	
	string takeAllItems();

private:
	
};